#include "chessGame.hh"

namespace chess
{
ChessGame::ChessGame(int xGridAmount, int yGridAmount)
{
    grid.resize(xGridAmount*yGridAmount);
    int i = 0;
    for (int x = 0; x < xGridAmount; x++)
    {
        for (int y = 0; y < yGridAmount; y++)
        {
            if (x % 2 == y % 2)
            {
                grid[i++] = new chess::GridSquare(x, y, {0xaa, 0xaa, 0xaa, 0xff}, true);
            }
            else
            {
                grid[i++] = new chess::GridSquare(x, y, {0x77, 0x77, 0x77, 0xff}, true);
            }
        }
    }
    this->squareSize = 0;
    this->xDisplacement = 0;
    this->yDisplacement = 0;
}

void ChessGame::updateSizes(int width, int height, int margin, int xGridAmount, int yGridAmount)
{
    squareSize = ((100 - margin * 2) * std::min(height / yGridAmount, width / xGridAmount) / 100);
    xDisplacement = (width - squareSize * xGridAmount) / 2;
    yDisplacement = (height - squareSize * yGridAmount) / 2;
}

void ChessGame::displayGrid(sdl::render::Renderer &rr)
{
    for (auto &g : grid)
    {
        g->display(rr, squareSize, xDisplacement, yDisplacement);
    }
}
} // namespace chess