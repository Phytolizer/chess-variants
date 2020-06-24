/**
 * @file weak_surface.hh
 * @author your name (you@domain.com)
 * @brief Contains the WeakSurface class
 * @date 2020-06-23
 */

#ifndef SDL_WRAPPER_SURFACE_WEAK_SURFACE_HH
#define SDL_WRAPPER_SURFACE_WEAK_SURFACE_HH

#include "SDL2/SDL_surface.h"
namespace sdl::surface
{
class WeakSurface
{
  public:
    WeakSurface(SDL_Surface *handle);
    SDL_Surface *getHandle();

  protected:
    SDL_Surface *handle;
};
} // namespace sdl::surface

#endif // SDL_WRAPPER_SURFACE_WEAK_SURFACE_HH