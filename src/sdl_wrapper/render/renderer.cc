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

void Renderer::setDrawColor(SDL_Color dc)
{
    int code = SDL_SetRenderDrawColor(handle, dc.r, dc.g, dc.b, dc.a);
    if (code != 0)
    {
        throw SDLException("setting renderer draw color");
    }
}

void Renderer::drawLine(SDL_Point p1, SDL_Point p2)
{
    int code = SDL_RenderDrawLine(handle, p1.x, p1.y, p2.x, p2.y);
    if (code != 0)
    {
        throw SDLException("drawing line to renderer");
    }
}

void Renderer::drawLines(const std::vector<SDL_Point> &vertices)
{
    int code = SDL_RenderDrawLines(handle, vertices.data(), vertices.size());
    if (code != 0)
    {
        throw SDLException("drawing lines to renderer");
    }
}

void Renderer::drawPoint(SDL_Point p)
{
    int code = SDL_RenderDrawPoint(handle, p.x, p.y);
    if (code != 0)
    {
        throw SDLException("drawing point to renderer");
    }
}

void Renderer::drawPoints(const std::vector<SDL_Point> &points)
{
    int code = SDL_RenderDrawPoints(handle, points.data(), points.size());
    if (code != 0)
    {
        throw SDLException("drawing points to renderer");
    }
}

void Renderer::drawRect(SDL_Rect r)
{
    int code = SDL_RenderDrawRect(handle, &r);
    if (code != 0)
    {
        throw SDLException("drawing rect to renderer");
    }
}

void Renderer::drawRects(const std::vector<SDL_Rect> &rects)
{
    int code = SDL_RenderDrawRects(handle, rects.data(), rects.size());
    if (code != 0)
    {
        throw SDLException("drawing rects to renderer");
    }
}

void Renderer::fillRect(SDL_Rect r)
{
    int code = SDL_RenderFillRect(handle, &r);
    if (code != 0)
    {
        throw SDLException("filling rect to renderer");
    }
}

void Renderer::fillRects(const std::vector<SDL_Rect> &rects)
{
    int code = SDL_RenderFillRects(handle, rects.data(), rects.size());
    if (code != 0)
    {
        throw SDLException("filling rects to renderer");
    }
}

void Renderer::present() noexcept
{
    SDL_RenderPresent(handle);
}

SDL_Renderer *Renderer::getHandle() const
{
    return handle;
}

} // namespace sdl::render