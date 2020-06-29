#include "weak_renderer.hh"
#include <cstring>
#include <sdl_wrapper/render/texture.hh>
#include <sdl_wrapper/sdl_exception.hh>

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
    SDL_BlendMode mode{};
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
    return WeakTexture(SDL_GetRenderTarget(handle), 0, 0);
}

void WeakRenderer::clear()
{
    int code = SDL_RenderClear(handle);
    if (code != 0)
    {
        throw SDLException("clearing renderer");
    }
}

void WeakRenderer::copy(const WeakTexture texture, std::optional<SDL_Rect> src, std::optional<SDL_Rect> dest)
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

void WeakRenderer::copy(const WeakTexture texture, std::optional<SDL_Rect> src, std::optional<SDL_Rect> dest, double angle,
                        std::optional<SDL_Point> center, SDL_RendererFlip flip)
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

SDL_RendererInfo WeakRenderer::getInfo() const
{
    SDL_RendererInfo info;
    int code = SDL_GetRendererInfo(handle, &info);
    if (code != 0)
    {
        throw SDLException("getting renderer info");
    }
    return info;
}

SDL_Rect WeakRenderer::getOutputSize() const
{
    SDL_Rect outputSize;
    int code = SDL_GetRendererOutputSize(handle, &outputSize.w, &outputSize.h);
    if (code != 0)
    {
        throw SDLException("getting renderer output size");
    }
    return outputSize;
}

SDL_Rect WeakRenderer::getClip() const noexcept
{
    SDL_Rect clip;
    SDL_RenderGetClipRect(handle, &clip);
    return clip;
}

bool WeakRenderer::isIntegerScale() const
{
    // this function is bad at telling when an error occurred, we must use the return value of SDL_GetError() to be sure
    SDL_ClearError();
    SDL_bool intScale = SDL_RenderGetIntegerScale(handle);
    if (intScale == SDL_FALSE && std::strlen(SDL_GetError()) != 0)
    {
        throw SDLException("getting renderer integer scale");
    }
    return intScale == SDL_TRUE;
}

SDL_Rect WeakRenderer::getLogicalSize() const noexcept
{
    SDL_Rect logicalSize;
    SDL_RenderGetLogicalSize(handle, &logicalSize.w, &logicalSize.h);
    return logicalSize;
}

ScalingFactors WeakRenderer::getScale() const noexcept
{
    ScalingFactors scale{};
    SDL_RenderGetScale(handle, &scale.scaleX, &scale.scaleY);
    return scale;
}

SDL_Rect WeakRenderer::getViewport() const noexcept
{
    SDL_Rect viewport;
    SDL_RenderGetViewport(handle, &viewport);
    return viewport;
}

bool WeakRenderer::isClipEnabled() const noexcept
{
    SDL_bool enabled = SDL_RenderIsClipEnabled(handle);
    return enabled == SDL_TRUE;
}

void WeakRenderer::setClip(SDL_Rect clipRect)
{
    int code = SDL_RenderSetClipRect(handle, &clipRect);
    if (code != 0)
    {
        throw SDLException("setting renderer clip rect");
    }
}

void WeakRenderer::setIntegerScale(bool forceIntegerScale)
{
    int code = SDL_RenderSetIntegerScale(handle, forceIntegerScale ? SDL_TRUE : SDL_FALSE);
    if (code != 0)
    {
        throw SDLException("setting renderer integer scale");
    }
}

void WeakRenderer::setLogicalSize(SDL_Rect size)
{
    int code = SDL_RenderSetLogicalSize(handle, size.w, size.h);
    if (code != 0)
    {
        throw SDLException("setting renderer logical size");
    }
}

void WeakRenderer::setScale(ScalingFactors scale)
{
    int code = SDL_RenderSetScale(handle, scale.scaleX, scale.scaleY);
    if (code != 0)
    {
        throw SDLException("setting renderer scale");
    }
}

void WeakRenderer::setViewport(SDL_Rect viewport)
{
    int code = SDL_RenderSetViewport(handle, &viewport);
    if (code != 0)
    {
        throw SDLException("setting renderer viewport");
    }
}

bool WeakRenderer::targetSupported() const noexcept
{
    SDL_bool supported = SDL_RenderTargetSupported(handle);
    return supported == SDL_TRUE;
}

void WeakRenderer::setBlendMode(SDL_BlendMode mode)
{
    int code = SDL_SetRenderDrawBlendMode(handle, mode);
    if (code != 0)
    {
        throw SDLException("setting renderer draw blend mode");
    }
}

void WeakRenderer::setTarget(WeakTexture texture)
{
    int code = SDL_SetRenderTarget(handle, texture.getHandle());
    if (code != 0)
    {
        throw SDLException("setting renderer target");
    }
}

void WeakRenderer::resetTarget()
{
    int code = SDL_SetRenderTarget(handle, nullptr);
    if (code != 0)
    {
        throw SDLException("resetting renderer target");
    }
}
} // namespace sdl::render