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
/**
 * @brief Represents the environment of a game of chess. Mainly involves the board for now.
 *
 * @todo add pieces
 */
class ChessGame
{
  public:
    /**
     * @brief Construct a new chess board with the specified size
     *
     * @param xGridAmount the number of columns
     * @param yGridAmount the number of rows
     */
    ChessGame(int xGridAmount, int yGridAmount);
    /**
     * @brief Compute the new size for the board given the screen space.
     *
     * @param width the screen width
     * @param height the screen height
     * @param margin the amount of space between the edges of the screen and the edges of the board
     * @param xGridAmount the number of columns in the board
     * @param yGridAmount the number of rows in the board
     */
    void updateSizes(int width, int height, int margin, int xGridAmount, int yGridAmount);
    /**
     * @brief Display the grid using the renderer provided.
     *
     * @param rr the renderer
     */
    void displayGrid(sdl::render::Renderer &rr);

  protected:
    /**
     * @brief The chess board. Contains grid square objects.
     *
     */
    std::vector<chess::GridSquare *> grid;
    /**
     * @brief The size of each grid square in pixels.
     *
     */
    int squareSize;
    /**
     * @brief The displacement in the x direction from the left-hand edge of the screen.
     *
     */
    int xDisplacement;
    /**
     * @brief The displacement in the y direction from the top edge of the screen.
     *
     */
    int yDisplacement;
};
} // namespace chess

#endif // CHESS_CHESS_HH