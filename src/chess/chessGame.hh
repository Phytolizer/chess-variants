/**
 * @file chessGame.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief For now, only contains documentation.
 * @date 2020-06-24
 */

#ifndef CHESS_CHESS_HH
#define CHESS_CHESS_HH

#include <algorithm>
#include <chess/gridSquare.hh>
#include <vector>

/**
 * @namespace chess
 * @brief Contains game logic and data structures.
 *
 */
namespace chess
{
class ChessGame
{
  public:
    ChessGame(int xGridAmount, int yGridAmount);
    void updateSizes(int width, int height, int margin, int xGridAmount, int yGridAmount);
    void displayGrid(sdl::render::Renderer &rr);

  protected:
    std::vector<chess::GridSquare *> grid;
    int squareSize;
    int xDisplacement;
    int yDisplacement;
};
} // namespace chess

#endif // CHESS_CHESS_HH