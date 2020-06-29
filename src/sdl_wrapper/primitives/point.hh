/**
 * @file point.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the Point struct
 * @date 2020-06-29
 */

#ifndef SDL_PRIMITIVES_POINT_HH
#define SDL_PRIMITIVES_POINT_HH

#include <SDL2/SDL_rect.h>

/**
 * @namespace sdl::primitives
 * @brief Contains various data structures representing primitives.
 *
 */
namespace sdl::primitives
{
struct Point : public SDL_Point
{
  public:
    bool operator<(const SDL_Point &other) const;
  private:
};
} // namespace sdl::primitives

#endif // SDL_PRIMITIVES_POINT_HH