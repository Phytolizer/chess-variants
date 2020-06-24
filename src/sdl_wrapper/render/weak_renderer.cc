#include "weak_renderer.hh"
#include <sdl_wrapper/sdl_exception.hh>
#include <sdl_wrapper/render/texture.hh>

using std::optional;

namespace sdl::render
{
WeakRenderer::WeakRenderer(SDL_Renderer *handle) : handle(handle)
{
}

SDL_Renderer *WeakRenderer::getHandle() const
{
    return handle;
}
int WeakRenderer::getNumRenderDrivers()
{
    return SDL_GetNumRenderDrivers();
}

SDL_BlendMode WeakRenderer::getDrawBlendMode() const
{
    SDL_BlendMode mode;
    int code = SDL_GetRenderDrawBlendMode(handle, &mode);
    if (code != 0)
    {
        throw SDLException("getting renderer draw blend mode");
    }
    return mode;
}

SDL_Color WeakRenderer::getDrawColor() const
{
    SDL_Color color;
    int code = SDL_GetRenderDrawColor(handle, &color.r, &color.g, &color.b, &color.a);
    if (code != 0)
    {
        throw SDLException("getting renderer draw color");
    }
    return color;
}

WeakTexture WeakRenderer::getTarget() const
{
    return WeakTexture(SDL_GetRenderTarget(handle));
}

void WeakRenderer::clear()
{
    int code = SDL_RenderClear(handle);
    if (code != 0)
    {
        throw SDLException("clearing renderer");
    }
}

void WeakRenderer::copy(const Texture &texture, optional<SDL_Rect> src, optional<SDL_Rect> dest)
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

void WeakRenderer::copy(const Texture &texture, optional<SDL_Rect> src, optional<SDL_Rect> dest, double angle,
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

void WeakRenderer::setDrawColor(SDL_Color dc)
{
    int code = SDL_SetRenderDrawColor(handle, dc.r, dc.g, dc.b, dc.a);
    if (code != 0)
    {
        throw SDLException("setting renderer draw color");
    }
}

void WeakRenderer::drawLine(SDL_Point p1, SDL_Point p2)
{
    int code = SDL_RenderDrawLine(handle, p1.x, p1.y, p2.x, p2.y);
    if (code != 0)
    {
        throw SDLException("drawing line to renderer");
    }
}

void WeakRenderer::drawLines(const std::vector<SDL_Point> &vertices)
{
    int code = SDL_RenderDrawLines(handle, vertices.data(), vertices.size());
    if (code != 0)
    {
        throw SDLException("drawing lines to renderer");
    }
}

void WeakRenderer::drawPoint(SDL_Point p)
{
    int code = SDL_RenderDrawPoint(handle, p.x, p.y);
    if (code != 0)
    {
        throw SDLException("drawing point to renderer");
    }
}

void WeakRenderer::drawPoints(const std::vector<SDL_Point> &points)
{
    int code = SDL_RenderDrawPoints(handle, points.data(), points.size());
    if (code != 0)
    {
        throw SDLException("drawing points to renderer");
    }
}

void WeakRenderer::drawRect(SDL_Rect r)
{
    int code = SDL_RenderDrawRect(handle, &r);
    if (code != 0)
    {
        throw SDLException("drawing rect to renderer");
    }
}

void WeakRenderer::drawRects(const std::vector<SDL_Rect> &rects)
{
    int code = SDL_RenderDrawRects(handle, rects.data(), rects.size());
    if (code != 0)
    {
        throw SDLException("drawing rects to renderer");
    }
}

void WeakRenderer::fillRect(SDL_Rect r)
{
    int code = SDL_RenderFillRect(handle, &r);
    if (code != 0)
    {
        throw SDLException("filling rect to renderer");
    }
}

void WeakRenderer::fillRects(const std::vector<SDL_Rect> &rects)
{
    int code = SDL_RenderFillRects(handle, rects.data(), rects.size());
    if (code != 0)
    {
        throw SDLException("filling rects to renderer");
    }
}

void WeakRenderer::present() noexcept
{
    SDL_RenderPresent(handle);
}
} // namespace sdl::render