#include "renderer.hh"
#include <sdl_wrapper/render/texture.hh>
#include <sdl_wrapper/sdl_exception.hh>
#include <sdl_wrapper/video/window.hh>

using std::optional;

namespace sdl::render
{

Renderer::Renderer(video::Window &window, int index, Uint32 flags)
{
    handle = SDL_CreateRenderer(window.getHandle(), index, flags);
    if (handle == nullptr)
    {
        throw SDLException("creating window renderer");
    }
}

Renderer::Renderer(SDL_Renderer *handle) : handle(handle)
{
}

Renderer::~Renderer()
{
    if (handle != nullptr)
    {
        SDL_DestroyRenderer(handle);
    }
}

Renderer::Renderer(Renderer &&other)
{
    handle = other.handle;
    other.handle = nullptr;
}

Renderer &Renderer::operator=(Renderer &&other)
{
    if (&other != this)
    {
        handle = other.handle;
        other.handle = nullptr;
    }
    return *this;
}

int Renderer::getNumRenderDrivers()
{
    return SDL_GetNumRenderDrivers();
}

SDL_BlendMode Renderer::getDrawBlendMode() const
{
    SDL_BlendMode mode;
    int code = SDL_GetRenderDrawBlendMode(handle, &mode);
    if (code != 0)
    {
        throw SDLException("getting renderer draw blend mode");
    }
    return mode;
}

SDL_Color Renderer::getDrawColor() const
{
    SDL_Color color;
    int code = SDL_GetRenderDrawColor(handle, &color.r, &color.g, &color.b, &color.a);
    if (code != 0)
    {
        throw SDLException("getting renderer draw color");
    }
    return color;
}

WeakTexture Renderer::getTarget() const
{
    return WeakTexture(SDL_GetRenderTarget(handle));
}

void Renderer::clear()
{
    int code = SDL_RenderClear(handle);
    if (code != 0)
    {
        throw SDLException("clearing renderer");
    }
}

void Renderer::copy(const Texture &texture, optional<SDL_Rect> src, optional<SDL_Rect> dest)
{
    SDL_Rect *srcRect = nullptr;
    if (src)
    {
        srcRect = &*src;
    }
    SDL_Rect *destRect = nullptr;
    if (dest)
    {
        destRect = &*dest;
    }
    int code = SDL_RenderCopy(handle, texture.getHandle(), srcRect, destRect);
    if (code != 0)
    {
        throw SDLException("blitting to renderer");
    }
}

void Renderer::copy(const Texture &texture, optional<SDL_Rect> src, optional<SDL_Rect> dest, double angle,
                    optional<SDL_Point> center, SDL_RendererFlip flip)
{
    SDL_Rect *srcRect = nullptr;
    if (src)
    {
        srcRect = &*src;
    }
    SDL_Rect *destRect = nullptr;
    if (dest)
    {
        destRect = &*dest;
    }
    SDL_Point *centerP = nullptr;
    if (center)
    {
        centerP = &*center;
    }
    int code = SDL_RenderCopyEx(handle, texture.getHandle(), srcRect, destRect, angle, centerP, flip);
    if (code != 0)
    {
        throw SDLException("blitting to renderer");
    }
}

void Renderer::present()
{
    SDL_RenderPresent(handle);
}

SDL_Renderer *Renderer::getHandle() const
{
    return handle;
}

} // namespace sdl::render