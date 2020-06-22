#include "king.hh"

namespace chess
{

const std::vector<SDL_Point> King::validMoves = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
King::King(int x, int y, SDL_Color color)
{
    this->color = color;
    this->x = x;
    this->y = y;
    selected = false;
    hasCrown_ = false;
}

void King::display()
{
    // TODO
}

void King::displayTransparent()
{
    // TODO
}

std::vector<SDL_Point> King::getValidMoves()
{
    return King::validMoves;
}

bool King::validateMove(SDL_Point relMove)
{
    for (const SDL_Point &validMove : validMoves)
    {
        if (validMove.x == relMove.x && validMove.y == relMove.y)
        {
            return true;
        }
    }
    return false;
}
} // namespace chess