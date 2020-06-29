/**
 * @file gridSquare.hh
 * @author Brandon Coffey
 * @brief
 * @date 2020-06-22
 */

#ifndef CHESS_GRIDSQUARE_HH
#define CHESS_GRIDSQUARE_HH

#include <sdl_wrapper/render/renderer.hh>
namespace chess
{
/**
 * @brief A single square on a chess board.
 *
 */
class GridSquare
{
  public:
    /**
     * @brief Construct a new grid square with the specified position in the specified color.
     *
     * @param x the x position
     * @param y the y position
     * @param color the color
     * @param enabled is the square enabled (i.e. does it exist on this board)?
     */
    GridSquare(int x, int y, SDL_Color color, bool enabled);
    /**
     * @brief Show the grid square using the renderer provided.
     *
     * @param rr the renderer
     * @param size the size of the square
     * @param xDisplacement the x displacement of the square
     * @param yDisplacement the y displacement of the square
     */
    void display(sdl::render::Renderer &rr, int size, int xDisplacement, int yDisplacement);

  protected:
    /**
     * @brief The x position on the grid.
     * 
     */
    int xPos;
    /**
     * @brief The y position on the grid.
     * 
     */
    int yPos;
    /**
     * @brief The color.
     * 
     */
    SDL_Color color;
    /**
     * @brief Whether to render this square or consider it in play.
     * 
     */
    bool enabled;
};
} // namespace chess

#endif // CHESS_GRIDSQUARE_HH