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

void WeakSurface::fillRect(SDL_Rect rect, SDL_Color color)
{
    Uint32 iColor = (color.r << 3) + (color.g << 2) + (color.b << 1) + (color.a);
    int code = SDL_FillRect(handle, &rect, iColor);
    if (code != 0)
    {
        throw SDLException("filling surface rect");
    }
}

void WeakSurface::fillRects(std::vector<SDL_Rect> rects, SDL_Color color)
{
    Uint32 iColor = (color.r << 3) + (color.g << 2) + (color.b << 1) + (color.a);
    int code = SDL_FillRects(handle, rects.data(), rects.size(), iColor);
    if (code != 0)
    {
        throw SDLException("filling surface rects");
    }
}

SDL_Rect WeakSurface::getClip() const noexcept
{
    SDL_Rect rect;
    SDL_GetClipRect(handle, &rect);
    return rect;
}

SDL_Color WeakSurface::getColorKey() const
{
    SDL_Color color;
    Uint32 iColor;
    int code = SDL_GetColorKey(handle, &iColor);
    if (code != 0)
    {
        throw SDLException("getting surface color key");
    }
    color.r = (iColor & 0xff000000) >> 3;
    color.g = (iColor & 0x00ff0000) >> 2;
    color.b = (iColor & 0x0000ff00) >> 1;
    color.a = (iColor & 0x000000ff) >> 0;
    return color;
}

Uint8 WeakSurface::getAlphaMod() const
{
    Uint8 alpha;
    int code = SDL_GetSurfaceAlphaMod(handle, &alpha);
    if (code != 0)
    {
        throw SDLException("getting surface alpha mod");
    }
    return alpha;
}

SDL_BlendMode WeakSurface::getBlendMode() const
{
    SDL_BlendMode bm;
    int code = SDL_GetSurfaceBlendMode(handle, &bm);
    if (code != 0)
    {
        throw SDLException("getting surface blend mode");
    }
    return bm;
}

SDL_Color WeakSurface::getColorMod() const
{
    SDL_Color mod;
    int code = SDL_GetSurfaceColorMod(handle, &mod.r, &mod.g, &mod.b);
    if (code != 0)
    {
        throw SDLException("getting surface color mod");
    }
    return mod;
}

void WeakSurface::lock()
{
    int code = SDL_LockSurface(handle);
    if (code != 0)
    {
        throw SDLException("locking surface");
    }
}

void WeakSurface::unlock() noexcept
{
    SDL_UnlockSurface(handle);
}

void WeakSurface::setHandle(SDL_Surface *handle)
{
    this->handle = handle;
}
} // namespace sdl::surface