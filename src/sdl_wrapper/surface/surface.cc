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
Surface::Surface(void *pixels, int width, int height, int depth, int pitch, Uint32 rmask, Uint32 gmask, Uint32 bmask,
                 Uint32 amask)
    : WeakSurface(SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rmask, gmask, bmask, amask))
{
    if (handle == nullptr)
    {
        throw SDLException("creating surface from pixel data");
    }
}
Surface::Surface(int width, int height, int depth, Uint32 pixelFormat)
    : WeakSurface(SDL_CreateRGBSurfaceWithFormat(0, width, height, depth, pixelFormat))
{
    if (handle == nullptr)
    {
        throw SDLException("creating surface with pixel format");
    }
}
Surface::Surface(void *pixels, int width, int height, int depth, int pitch, Uint32 pixelFormat)
    : WeakSurface(SDL_CreateRGBSurfaceWithFormatFrom(pixels, width, height, depth, pitch, pixelFormat))
{
    if (handle == nullptr)
    {
        throw SDLException("creating surface with pixel format from pixel data");
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

Surface Surface::convert(SDL_PixelFormat fmt)
{
    SDL_Surface *nHandle = SDL_ConvertSurface(handle, &fmt, 0);
    if (nHandle == nullptr)
    {
        throw SDLException("converting surface");
    }
    return Surface(nHandle);
}

Surface Surface::convertFormat(Uint32 fmt)
{
    SDL_Surface *nHandle = SDL_ConvertSurfaceFormat(handle, fmt, 0);
    if (nHandle == nullptr)
    {
        throw SDLException("converting surface format");
    }
    return Surface(nHandle);
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

Surface loadBmp(std::string_view fileName)
{
    SDL_Surface *handle = SDL_LoadBMP(fileName.data());
    if (handle == nullptr)
    {
        throw SDLException("loading surface from BMP");
    }
    return Surface(handle);
}
} // namespace sdl::surface