#include "piece_file.hh"
#include <chess/piece_factory.hh>
#include <fstream>
#include <sdl_wrapper/render/texture.hh>
#include <string>
#include <util/util.hh>

namespace io
{
enum class PieceFileState
{
    PieceName,
    ValidMoves,
    WhiteFileName,
    BlackFileName,
    Done
};
chess::PieceFactory readPieceFile(sdl::image::Context &imgContext, std::string_view fileName)
{
    std::ifstream file(fileName.data());
    std::string line;
    std::vector<SDL_Point> validMoves;
    std::string whiteFile;
    std::string blackFile;
    std::string pieceName;
    PieceFileState state = PieceFileState::PieceName;
    int lineNum = 1;
    while (std::getline(file, line))
    {
        // ignore blank lines
        if (line.length() == 0 || util::trim(line).length() == 0)
        {
            continue;
        }
        // comments
        if (line[0] == '#')
        {
            continue;
        }
        switch (state)
        {
        case PieceFileState::PieceName: {
            pieceName = line;
            state = PieceFileState::ValidMoves;
            break;
        }
        case PieceFileState::ValidMoves: {
            if (util::trim(line) == "END")
            {
                state = PieceFileState::WhiteFileName;
            }
            else
            {
                auto comma = line.find(',');
                if (comma == std::string::npos)
                {
                    throw std::runtime_error(util::concat("reading piece file ", fileName, ": line ", lineNum,
                                                          ": invalid format for move '", line, "'\n"));
                }
                std::string xCoord = util::trim(line.substr(0, comma));
                std::string yCoord = util::trim(line.substr(comma + 1, line.length()));
                char *end;
                int x = std::strtol(xCoord.c_str(), &end, 10);
                if (xCoord.length() == 0 || *end != '\0')
                {
                    throw std::runtime_error(util::concat("reading piece file ", fileName, ": line ", lineNum, ": '",
                                                          xCoord, "' is not an integer\n"));
                }
                int y = std::strtol(yCoord.c_str(), &end, 10);
                if (yCoord.length() == 0 || *end != '\0')
                {
                    throw std::runtime_error(util::concat("reading piece file ", fileName, ": line ", lineNum, ": '",
                                                          yCoord, "' is not an integer\n"));
                }
                validMoves.push_back({x, y});
            }
            break;
        }
        case PieceFileState::WhiteFileName: {
            whiteFile = line;
            state = PieceFileState::BlackFileName;
            break;
        }
        case PieceFileState::BlackFileName: {
            blackFile = line;
            state = PieceFileState::Done;
            break;
        }
        case PieceFileState::Done: {
            throw std::runtime_error(util::concat("reading piece file ", fileName, ": line ", lineNum,
                                                  ": Unexpected line '", line, "', expected EOF\n"));
        }
        }
        lineNum += 1;
    }
    // load images
    auto whiteSurface = imgContext.load(whiteFile);
    auto blackSurface = imgContext.load(blackFile);
    return chess::PieceFactory(validMoves, std::move(whiteSurface), std::move(blackSurface));
}
} // namespace io