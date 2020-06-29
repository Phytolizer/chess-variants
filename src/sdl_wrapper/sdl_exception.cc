#include "sdl_exception.hh"
#include <SDL2/SDL_error.h>
#include <cstring>
#include <sstream>
#include <util/util.hh>

SDLException::SDLException(std::string_view message)
    : std::runtime_error(""), message(message.data()), sdl_error(SDL_GetError())
{
    if (message.empty())
    {
        what_str = sdl_error;
    }
    else
    {
        what_str = util::concat(message, ": ", sdl_error);
    }
}

const char *SDLException::what() const noexcept
{
    return what_str.c_str();
}