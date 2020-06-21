#include "sdl_context.hh"
#include <SDL2/SDL.h>
#include <sdl_wrapper/sdl_exception.hh>

SDLContext::SDLContext() : active(true)
{
    int code = SDL_Init(0);
    if (code != 0)
    {
        throw SDLException("initializing SDL");
    }
}

SDLContext::~SDLContext()
{
    if (active)
    {
        SDL_Quit();
    }
}

SDLContext::SDLContext(SDLContext &&other)
{
    active = other.active;
    other.active = false;
}

SDLContext &SDLContext::operator=(SDLContext &&other)
{
    if (&other != this)
    {
        active = other.active;
        other.active = false;
    }
    return *this;
}

SDLVideoContext SDLContext::initVideo()
{
    return SDLVideoContext(*this);
}