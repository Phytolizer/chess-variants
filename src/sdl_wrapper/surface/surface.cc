#include "surface.hh"
#include <SDL2/SDL_surface.h>
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::surface
{
Surface::Surface(SDL_Surface *handle) : WeakSurface(handle)
{
}
Surface::Surface(int width, int height, int depth, Uint32 rmask, Uint32 gmask, Uint32 bmask, Uint32 amask)
    : WeakSurface(SDL_CreateRGBSurface(0, width, height, depth, rmask, gmask, bmask, amask))
{
    if (handle == nullptr)
    {
        throw SDLException("creating surface");
    }
}
Surface::Surface(int width, int height, int depth, Uint32 pixelFormat)
    : WeakSurface(SDL_CreateRGBSurfaceWithFormat(0, width, height, depth, pixelFormat))
{
    if (handle == nullptr)
    {
        throw SDLException("creating surface");
    }
}
Surface::~Surface()
{
    if (handle != nullptr)
    {
        SDL_FreeSurface(handle);
    }
}

Surface::Surface(Surface &&other) : WeakSurface(other.handle)
{
    other.handle = nullptr;
}

Surface &Surface::operator=(Surface &&other)
{
    if (&other != this)
    {
        handle = other.handle;
        other.handle = nullptr;
    }
    return *this;
}

void convertPixels(int width, int height, Uint32 srcFormat, int srcPitch, const void *src, Uint32 dstFormat,
                   int dstPitch, void *dst)
{
    int code = SDL_ConvertPixels(width, height, srcFormat, src, srcPitch, dstFormat, dst, dstPitch);
    if (code != 0)
    {
        throw SDLException("converting between pixel formats");
    }
}
} // namespace sdl::surface