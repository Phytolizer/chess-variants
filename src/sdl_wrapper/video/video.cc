#include "video.hh"
#include <sdl_wrapper/sdl_exception.hh>
#include <util/util.hh>

using util::concat;

namespace sdl::video
{
int Display::getNumModes()
{
    int numDisplayModes = SDL_GetNumDisplayModes(index);
    if (numDisplayModes < 0)
    {
        throw SDLException(concat("getting number of display modes for display ", index));
    }
    return numDisplayModes;
}
SDL_DisplayMode Display::getClosestMode(const SDL_DisplayMode &mode)
{
    SDL_DisplayMode closest;
    SDL_DisplayMode *p = SDL_GetClosestDisplayMode(index, &mode, &closest);
    if (p == nullptr)
    {
        throw SDLException(concat("getting closest display mode for display ", index));
    }
    return closest;
}
SDL_DisplayMode Display::getCurrentMode()
{
    SDL_DisplayMode mode;
    int code = SDL_GetCurrentDisplayMode(index, &mode);
    if (code != 0)
    {
        throw SDLException(concat("getting current display mode for display ", index));
    }
    return mode;
}
SDL_DisplayMode Display::getDesktopDisplayMode()
{
    SDL_DisplayMode mode;
    int code = SDL_GetDesktopDisplayMode(index, &mode);
    if (code != 0)
    {
        throw SDLException(concat("getting desktop display mode for display ", index));
    }
    return mode;
}
SDL_Rect Display::getBounds()
{
    SDL_Rect bounds;
    int code = SDL_GetDisplayBounds(index, &bounds);
    if (code != 0)
    {
        throw SDLException(concat("getting display bounds for display ", index));
    }
    return bounds;
}
Dpi Display::getDpi()
{
    Dpi dpi;
    int code = SDL_GetDisplayDPI(index, &dpi.diag, &dpi.horz, &dpi.vert);
    if (code != 0)
    {
        throw SDLException(concat("getting DPI for display ", index));
    }
    return dpi;
}
SDL_DisplayMode Display::getModeInfo(int modeIndex)
{
    SDL_DisplayMode mode;
    int code = SDL_GetDisplayMode(index, modeIndex, &mode);
    if (code != 0)
    {
        throw SDLException(concat("getting display mode at ", modeIndex, " for display ", index));
    }
    return mode;
}
SDL_Rect Display::getUsableBounds()
{
    SDL_Rect bounds;
    int code = SDL_GetDisplayUsableBounds(index, &bounds);
    if (code != 0)
    {
        throw SDLException(concat("getting usable bounds for display ", index));
    }
    return bounds;
}
void enableScreenSaver() noexcept
{
    SDL_EnableScreenSaver();
}
void disableScreenSaver() noexcept
{
    SDL_DisableScreenSaver();
}
bool isScreenSaverEnabled() noexcept
{
    return SDL_IsScreenSaverEnabled();
}
std::string getCurrentVideoDriver()
{
    return SDL_GetCurrentVideoDriver();
}
std::optional<WeakWindow> getGrabbedWindow() noexcept
{
    SDL_Window *handle = SDL_GetGrabbedWindow();
    if (handle == nullptr)
    {
        return std::nullopt;
    }
    return {WeakWindow(handle)};
}
int getNumDisplays()
{
    int numDisplays = SDL_GetNumVideoDisplays();
    if (numDisplays < 0)
    {
        throw SDLException("getting number of displays");
    }
    return numDisplays;
}
int getNumVideoDrivers()
{
    int numVideoDrivers = SDL_GetNumVideoDrivers();
    if (numVideoDrivers < 0)
    {
        throw SDLException("getting number of video drivers");
    }
    return numVideoDrivers;
}
std::string getVideoDriver(int index)
{
    const char *driverName = SDL_GetVideoDriver(index);
    if (driverName == nullptr)
    {
        throw SDLException(concat("getting video driver at index ", index));
    }
    return driverName;
}
WeakWindow getWindowFromId(Uint32 id)
{
    SDL_Window *handle = SDL_GetWindowFromID(id);
    if (handle == nullptr)
    {
        throw SDLException("getting window from ID");
    }
    return WeakWindow(handle);
}
void init(std::optional<std::string_view> driverName)
{
    const char *driverNameP = nullptr;
    if (driverName)
    {
        driverNameP = driverName->data();
    }
    int code = SDL_VideoInit(driverNameP);
    if (code != 0)
    {
        throw SDLException("initializing SDL video subsystem");
    }
}
void quit() noexcept
{
    SDL_VideoQuit();
}

std::pair<Window, render::Renderer> createWindowAndRenderer(int width, int height, Uint32 windowFlags)
{
    SDL_Window *wHandle;
    SDL_Renderer *rHandle;
    int code = SDL_CreateWindowAndRenderer(width, height, windowFlags, &wHandle, &rHandle);
    if (code != 0)
    {
        throw SDLException("creating window and renderer");
    }
    return {Window(wHandle), render::Renderer(rHandle)};
}
} // namespace sdl::video