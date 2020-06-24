#include "weak_surface.hh"
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::surface
{
WeakSurface::WeakSurface(SDL_Surface *handle) : handle(handle)
{
}

SDL_Surface *WeakSurface::getHandle() const
{
    return handle;
}

void WeakSurface::blitScaledTo(std::optional<SDL_Rect> clip, WeakSurface dest, std::optional<SDL_Rect> destRect)
{
    SDL_Rect *sr = nullptr;
    if (clip)
    {
        sr = &*clip;
    }
    SDL_Rect *dr = nullptr;
    if (destRect)
    {
        dr = &*destRect;
    }
    int code = SDL_BlitScaled(handle, sr, dest.getHandle(), dr);
    if (code != 0)
    {
        throw SDLException("blitting surface scaled to surface");
    }
}

void WeakSurface::blitTo(std::optional<SDL_Rect> clip, WeakSurface dest, std::optional<SDL_Rect> destRect)
{
    SDL_Rect *sr = nullptr;
    if (clip)
    {
        sr = &*clip;
    }
    SDL_Rect *dr = nullptr;
    if (destRect)
    {
        dr = &*destRect;
    }
    int code = SDL_BlitSurface(handle, sr, dest.getHandle(), dr);
    if (code != 0)
    {
        throw SDLException("blitting surface to surface");
    }
}

Surface WeakSurface::convertSurface(const SDL_PixelFormat &fmt)
{
    SDL_Surface *nHandle = SDL_ConvertSurface(handle, &fmt, 0);
    if (nHandle == nullptr)
    {
        throw SDLException("converting surface");
    }
    return Surface(nHandle);
}

} // namespace sdl::surface