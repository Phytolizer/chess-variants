#include "chessGame.hh"
#include <sdl_wrapper/colors.hh>

namespace chess
{
ChessGame::ChessGame(int xGridAmount, int yGridAmount)
{
    grid.resize(xGridAmount * yGridAmount);
    int i = 0;
    for (int x = 0; x < xGridAmount; x++)
    {
        for (int y = 0; y < yGridAmount; y++)
        {
            constexpr SDL_Color LIGHT_GRAY = {0xaa, 0xaa, 0xaa, 0xff};
            constexpr SDL_Color DARK_GRAY = {0x77, 0x77, 0x77, 0xff};
            if (x % 2 == y % 2)
            {
                grid[i++] = new chess::GridSquare(x, y, LIGHT_GRAY, true);
            }
            else
            {
                grid[i++] = new chess::GridSquare(x, y, DARK_GRAY, true);
            }
        }
    }
    this->chessBoard = std::nullopt;
    this->squareSize = 0;
    this->xDisplacement = 0;
    this->yDisplacement = 0;
}

void ChessGame::redraw(sdl::render::Renderer &rr, int width, int height, int margin, int nCols, int nRows)
{
    squareSize = ((100 - margin * 2) * std::min(height / nRows, width / nCols) / 100);
    constexpr int HUNDRED_PERCENT = 100;
    squareSize = ((HUNDRED_PERCENT - margin * 2) * std::min(height / nRows, width / nCols) / HUNDRED_PERCENT);
    xDisplacement = (width - squareSize * nCols) / 2;
    yDisplacement = (height - squareSize * nRows) / 2;
    int oldW = chessBoard ? chessBoard->getWidth() : 0;
    int oldH = chessBoard ? chessBoard->getHeight() : 0;
    chessBoard = {sdl::render::Texture(rr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, squareSize * nCols,
                                       squareSize * nRows)};
    rr.setTarget(*chessBoard);
    rr.setDrawColor(sdl::colors::Transparent);
    rr.clear();
    for (auto &square : grid)
    {
        square->display(rr, squareSize, 0, 0);
    }
    rr.resetTarget();
}

void ChessGame::displayGrid(sdl::render::Renderer &rr)
{
    rr.copy(*chessBoard, std::nullopt,
            {{xDisplacement, yDisplacement, chessBoard->getWidth(), chessBoard->getHeight()}});
}
} // namespace chess