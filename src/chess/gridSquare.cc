#include "gridSquare.hh"

namespace chess
{
GridSquare::GridSquare(int x, int y, SDL_Color c, bool e) : xPos(x), yPos(y), color(c), enabled(e)
{
}
void GridSquare::display(sdl::render::Renderer &rr, int size, int xDisplacement, int yDisplacement)
{
    rr.setDrawColor(color);
    rr.fillRect({xPos * size + xDisplacement, yPos * size + yDisplacement, size, size});
}
} // namespace chess