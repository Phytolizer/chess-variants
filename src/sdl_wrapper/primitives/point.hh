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
/**
 * @brief Extension of the SDL_Point struct.
 * 
 */
struct Point : public SDL_Point
{
  public:
    /**
     * @brief Compare two points.
     * 
     * @param other the other point
     * @return true the magnitude of this point is less than the other's
     * @return false the magnitude of this point is not less than the other's
     */
    bool operator<(const SDL_Point &other) const;
  private:
};
} // namespace sdl::primitives

#endif // SDL_PRIMITIVES_POINT_HH