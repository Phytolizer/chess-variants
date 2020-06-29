#include "piece_file.hh"
#include <chess/piece_factory.hh>
#include <fstream>
#include <sdl_wrapper/colors.hh>
#include <sdl_wrapper/render/texture.hh>
#include <string>
#include <util/util.hh>

namespace io
{
/**
 * @brief The state we're in while parsing a piece file.
 *
 */
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
    std::set<SDL_Point> validMoves;
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
                // string representation of x coordinate
                std::string xCoord = util::trim(line.substr(0, comma));
                // string representation of y coordinate
                std::string yCoord = util::trim(line.substr(comma + 1, line.length()));

                // this initial value is never read if an exception is not thrown

                int x = 0;
                int y = 0;

                // parse coordinates to integers
                try
                {
                    x = util::parseInt(xCoord);
                }
                catch (std::runtime_error &e)
                {
                    throw std::runtime_error(
                        util::concat("reading piece file ", fileName, ": line ", lineNum, ": ", e.what()));
                }
                try
                {
                    y = util::parseInt(yCoord);
                }
                catch (std::runtime_error &e)
                {
                    throw std::runtime_error(
                        util::concat("reading piece file ", fileName, ": line ", lineNum, ": ", e.what()));
                }

                // append to list
                validMoves.insert({x, y});
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