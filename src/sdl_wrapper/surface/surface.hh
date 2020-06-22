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

namespace sdl::surface
{
class Surface
{
  public:
    Surface(int width, int height, int depth, Uint32 rmask, Uint32 gmask, Uint32 bmask, Uint32 amask);
    Surface(int width, int height, int depth, Uint32 pixelFormat);
    Surface(SDL_Surface *handle) __attribute__((nonnull(2)));

    ~Surface();

    Surface(const Surface &) = delete;
    Surface &operator=(const Surface &) = delete;

    Surface(Surface &&other);
    Surface &operator=(Surface &&other);

    SDL_Surface *getHandle() const;

  private:
    SDL_Surface *handle;
};
} // namespace sdl::surface

#endif // SDL_WRAPPER_SURFACE_SURFACE_HH