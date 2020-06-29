#include "context.hh"
#include <SDL2/SDL.h>
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl
{
Context::Context() : active(true)
{
    int code = SDL_Init(0);
    if (code != 0)
    {
        throw SDLException("initializing SDL");
    }
}

Context::~Context()
{
    if (active)
    {
        SDL_Quit();
    }
}

Context::Context(Context &&other) noexcept : active(other.active)
{
    other.active = false;
}

Context &Context::operator=(Context &&other) noexcept
{
    if (&other != this)
    {
        active = other.active;
        other.active = false;
    }
    return *this;
}

video::Context Context::initVideo()
{
    return video::Context(*this);
}
} // namespace sdl