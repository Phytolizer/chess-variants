#include "context.hh"
#include <SDL2/SDL.h>
#include <sdl_wrapper/sdl_exception.hh>
#include <sdl_wrapper/video/video.hh>

namespace sdl::video
{
Context::Context(::sdl::Context &) : active(true), onQuit([]() { SDL_QuitSubSystem(SDL_INIT_VIDEO); })
{
    int code = SDL_InitSubSystem(SDL_INIT_VIDEO);
    if (code != 0)
    {
        throw SDLException("initializing SDL video subsystem");
    }
}
Context::Context(::sdl::Context &, std::string_view driverName) : active(true), onQuit(SDL_VideoQuit)
{
    init({driverName});
}

Context::~Context()
{
    if (active)
    {
        onQuit();
    }
}

Context::Context(Context &&other)
{
    active = other.active;
    other.active = false;
}

Context &Context::operator=(Context &&other)
{
    if (&other != this)
    {
        active = other.active;
        other.active = false;
    }
    return *this;
}

WindowBuilder Context::createWindow(std::string_view title, int x, int y, int w, int h)
{
    return WindowBuilder(*this, title, x, y, w, h);
}
} // namespace sdl::video