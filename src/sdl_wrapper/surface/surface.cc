#include "surface.hh"
#include <SDL2/SDL_surface.h>
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::surface
{
Surface::Surface(int width, int height, int depth, Uint32 rmask, Uint32 gmask, Uint32 bmask, Uint32 amask)
{
    handle = SDL_CreateRGBSurface(0, width, height, depth, rmask, gmask, bmask, amask);
    if (handle == nullptr)
    {
        throw SDLException("creating surface");
    }
}
Surface::Surface(int width, int height, int depth, Uint32 pixelFormat)
{
    handle = SDL_CreateRGBSurfaceWithFormat(0, width, height, depth, pixelFormat);
    if (handle == nullptr)
    {
        throw SDLException("creating surface");
    }
}
Surface::Surface(SDL_Surface *handle) : handle(handle)
{
}
SDL_Surface *Surface::getHandle() const
{
    return handle;
}

Surface::~Surface()
{
    if (handle != nullptr)
    {
        SDL_FreeSurface(handle);
    }
}

Surface::Surface(Surface &&other)
{
    handle = other.handle;
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
} // namespace sdl::surface