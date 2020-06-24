/**
 * @file surface.hh
 * @author your name (you@domain.com)
 * @brief Contains a wrapper for SDL_Surface
 * @date 2020-06-22
 */

#ifndef SDL_WRAPPER_SURFACE_SURFACE_HH
#define SDL_WRAPPER_SURFACE_SURFACE_HH

#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <sdl_wrapper/surface/weak_surface.hh>

namespace sdl::surface
{
  /**
   * @brief A structured collection of pixels used in software rendering. Hardware rendering is not
   * done with surfaces.
   *
   * @see sdl::render::Renderer
   * 
   */
class Surface : public WeakSurface
{
  public:
    Surface(int width, int height, int depth, Uint32 rmask, Uint32 gmask, Uint32 bmask, Uint32 amask);
    Surface(int width, int height, int depth, Uint32 pixelFormat);

    ~Surface();

    Surface(const Surface &) = delete;
    Surface &operator=(const Surface &) = delete;

    Surface(Surface &&other);
    Surface &operator=(Surface &&other);
};
} // namespace sdl::surface

#endif // SDL_WRAPPER_SURFACE_SURFACE_HH