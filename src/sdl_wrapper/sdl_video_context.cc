#include "sdl_video_context.hh"
#include <SDL2/SDL.h>
#include <sdl_wrapper/sdl_exception.hh>

SDLVideoContext::SDLVideoContext(SDLContext &sdl) : active(true)
{
    int code = SDL_InitSubSystem(SDL_INIT_VIDEO);
    if (code != 0)
    {
        throw SDLException("initializing SDL video subsystem");
    }
}

SDLVideoContext::SDLVideoContext(SDLVideoContext &&other)
{
    active = other.active;
    other.active = false;
}

SDLVideoContext &SDLVideoContext::operator=(SDLVideoContext &&other)
{
    if (&other != this)
    {
        active = other.active;
        other.active = false;
    }
    return *this;
}