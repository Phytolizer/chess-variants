#include "point.hh"

namespace sdl::primitives
{
bool Point::operator<(const SDL_Point &other) const
{
    return (x * x + y * y) < (other.x * other.x + other.y * other.y);
}
} // namespace sdl::primitives