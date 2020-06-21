#include "context.hh"
#include <SDL2/SDL.h>
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::video
{
Context::Context(::sdl::Context &sdl) : active(true)
{
    int code = SDL_InitSubSystem(SDL_INIT_VIDEO);
    if (code != 0)
    {
        throw SDLException("initializing SDL video subsystem");
    }
}

Context::~Context()
{
    if (active)
    {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
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
} // namespace sdl::video