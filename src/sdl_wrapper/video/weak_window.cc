#include "weak_window.hh"
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::video
{
WeakWindow::WeakWindow(SDL_Window *handle) : handle(handle)
{
}

SDL_Window *WeakWindow::getHandle()
{
    return handle;
}
WindowBordersSize WeakWindow::getBordersSize() const
{
    WindowBordersSize bordersSize;
    int code =
        SDL_GetWindowBordersSize(handle, &bordersSize.top, &bordersSize.left, &bordersSize.bottom, &bordersSize.right);
    if (code != 0)
    {
        throw SDLException("getting borders size for window");
    }
    return bordersSize;
}
float WeakWindow::getBrightness() const noexcept
{
    return SDL_GetWindowBrightness(handle);
}
void *WeakWindow::getDataPtr(std::string_view name) noexcept
{
    return SDL_GetWindowData(handle, name.data());
}
int WeakWindow::getDisplayIndex() const
{
    int index = SDL_GetWindowDisplayIndex(handle);
    if (index < 0)
    {
        throw SDLException("getting window's display index");
    }
    return index;
}
Uint32 WeakWindow::getFlags() const noexcept
{
    return SDL_GetWindowFlags(handle);
}
GammaRamp WeakWindow::getGammaRamp() const
{
    GammaRamp ramp;
    int code = SDL_GetWindowGammaRamp(handle, ramp.red.data(), ramp.green.data(), ramp.blue.data());
    if (code != 0)
    {
        throw SDLException("getting display gamma ramp");
    }
    return ramp;
}
bool WeakWindow::isGrabbed() const noexcept
{
    return SDL_GetWindowGrab(handle);
}
Uint32 WeakWindow::getId() const
{
    Uint32 id = SDL_GetWindowID(handle);
    if (id == 0)
    {
        throw SDLException("getting window's ID");
    }
    return id;
}
SDL_Rect WeakWindow::getMaxSize() const noexcept
{
    SDL_Rect maxSize;
    SDL_GetWindowMaximumSize(handle, &maxSize.w, &maxSize.h);
    return maxSize;
}
SDL_Rect WeakWindow::getMinSize() const noexcept
{
    SDL_Rect minSize;
    SDL_GetWindowMinimumSize(handle, &minSize.w, &minSize.h);
    return minSize;
}
float WeakWindow::getOpacity() const
{
    float opacity;
    int code = SDL_GetWindowOpacity(handle, &opacity);
    if (code != 0)
    {
        throw SDLException("getting window's opacity");
    }
    return opacity;
}
Uint32 WeakWindow::getPixelFormat() const
{
    Uint32 pixelFormat = SDL_GetWindowPixelFormat(handle);
    if (pixelFormat == SDL_PIXELFORMAT_UNKNOWN)
    {
        throw SDLException("getting window's pixel format");
    }
    return pixelFormat;
}
SDL_Point WeakWindow::getPosition() const noexcept
{
    SDL_Point pos;
    SDL_GetWindowPosition(handle, &pos.x, &pos.y);
    return pos;
}
SDL_Rect WeakWindow::getSize() const noexcept
{
    SDL_Rect size;
    SDL_GetWindowSize(handle, &size.w, &size.h);
    return size;
}
surface::WeakSurface WeakWindow::getSurface()
{
    SDL_Surface *surf = SDL_GetWindowSurface(handle);
    if (surf == nullptr)
    {
        throw SDLException("getting window's surface");
    }
    return surface::WeakSurface(surf);
}
std::string WeakWindow::getTitle() const noexcept
{
    return SDL_GetWindowTitle(handle);
}
SDL_SysWMinfo WeakWindow::getWmInfo() const
{
    SDL_SysWMinfo info;
    SDL_bool valid = SDL_GetWindowWMInfo(handle, &info);
    if (valid == SDL_FALSE)
    {
        throw SDLException("getting window's WM info");
    }
    return info;
}
render::RendererBuilder WeakWindow::createRenderer()
{
    return render::RendererBuilder(*this);
}
void WeakWindow::hide() noexcept
{
    SDL_HideWindow(handle);
}
void WeakWindow::maximize() noexcept
{
    SDL_MaximizeWindow(handle);
}
void WeakWindow::minimize() noexcept
{
    SDL_MinimizeWindow(handle);
}
void WeakWindow::raise() noexcept
{
    SDL_RaiseWindow(handle);
}
void WeakWindow::restore() noexcept
{
    SDL_RestoreWindow(handle);
}
void WeakWindow::setHasBorder(bool bordered) noexcept
{
    SDL_SetWindowBordered(handle, bordered ? SDL_TRUE : SDL_FALSE);
}
void WeakWindow::setBrightness(float brightness)
{
    int code = SDL_SetWindowBrightness(handle, brightness);
    if (code != 0)
    {
        throw SDLException("setting window brightness");
    }
}
void WeakWindow::setDisplayMode(const SDL_DisplayMode &mode)
{
    int code = SDL_SetWindowDisplayMode(handle, &mode);
    if (code != 0)
    {
        throw SDLException("setting window display mode");
    }
}
void WeakWindow::setFullscreen()
{
    int code = SDL_SetWindowFullscreen(handle, SDL_WINDOW_FULLSCREEN);
    if (code != 0)
    {
        throw SDLException("setting window to fullscreen");
    }
}
void WeakWindow::setFullscreenDesktop()
{
    int code = SDL_SetWindowFullscreen(handle, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (code != 0)
    {
        throw SDLException("setting window to fullscreen-desktop");
    }
}
void WeakWindow::setWindowed()
{
    int code = SDL_SetWindowFullscreen(handle, 0);
    if (code != 0)
    {
        throw SDLException("setting window to windowed mode");
    }
}
void WeakWindow::setGammaRamp(const GammaRamp &ramp)
{
    int code = SDL_SetWindowGammaRamp(handle, ramp.red.data(), ramp.green.data(), ramp.blue.data());
    if (code != 0)
    {
        throw SDLException("setting display gamma ramp");
    }
}
void WeakWindow::setInputGrabbed(bool grabbed) noexcept
{
    SDL_SetWindowGrab(handle, grabbed ? SDL_TRUE : SDL_FALSE);
}
void WeakWindow::setHitTest(SDL_HitTest callback, void *callbackData)
{
    int code = SDL_SetWindowHitTest(handle, callback, callbackData);
    if (code != 0)
    {
        throw SDLException("setting window hit test callback");
    }
}
void WeakWindow::setIcon(surface::WeakSurface icon) noexcept
{
    SDL_SetWindowIcon(handle, icon.getHandle());
}
void WeakWindow::setAsFocus()
{
    int code = SDL_SetWindowInputFocus(handle);
    if (code != 0)
    {
        throw SDLException("setting window as focus");
    }
}
void WeakWindow::setMaxSize(SDL_Rect maxSize) noexcept
{
    SDL_SetWindowMaximumSize(handle, maxSize.w, maxSize.h);
}
void WeakWindow::setMinSize(SDL_Rect minSize) noexcept
{
    SDL_SetWindowMinimumSize(handle, minSize.w, minSize.h);
}
void WeakWindow::setAsModalFor(WeakWindow parent)
{
    int code = SDL_SetWindowModalFor(handle, parent.getHandle());
    if (code != 0)
    {
        throw SDLException("setting window as modal");
    }
}
void WeakWindow::setOpacity(float opacity)
{
    int code = SDL_SetWindowOpacity(handle, opacity);
    if (code != 0)
    {
        throw SDLException("setting window opacity");
    }
}
void WeakWindow::setPosition(SDL_Point position) noexcept
{
    SDL_SetWindowPosition(handle, position.x, position.y);
}
void WeakWindow::setResizable(bool resizable) noexcept
{
    SDL_SetWindowResizable(handle, resizable ? SDL_TRUE : SDL_FALSE);
}
void WeakWindow::setSize(SDL_Rect size) noexcept
{
    SDL_SetWindowSize(handle, size.w, size.h);
}
void WeakWindow::setTitle(std::string_view title) noexcept
{
    SDL_SetWindowTitle(handle, title.data());
}
void WeakWindow::updateSurface()
{
    int code = SDL_UpdateWindowSurface(handle);
    if (code != 0)
    {
        throw SDLException("updating window surface");
    }
}
void WeakWindow::updateSurfaceAreas(std::vector<SDL_Rect> areas)
{
    int code = SDL_UpdateWindowSurfaceRects(handle, areas.data(), areas.size());
    if (code != 0)
    {
        throw SDLException("updating window surface areas");
    }
}
render::WeakRenderer WeakWindow::getRenderer()
{
    SDL_Renderer *rHandle = SDL_GetRenderer(handle);
    if (rHandle == nullptr)
    {
        throw SDLException("getting window renderer");
    }
    return render::WeakRenderer(rHandle);
}
} // namespace sdl::video