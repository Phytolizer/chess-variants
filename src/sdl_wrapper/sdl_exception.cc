#include "sdl_exception.hh"
#include <SDL2/SDL_error.h>
#include <cstring>
#include <sstream>

SDLException::SDLException(std::string_view message)
    : std::runtime_error(""), message(message.data()), sdl_error(SDL_GetError())
{
}

const char *SDLException::what() const noexcept
{
    std::stringstream ss;
    if (message.empty())
    {
        ss << sdl_error;
    }
    else
    {
        ss << message << ": " << sdl_error;
    }
    std::string whatStr = ss.str();
    char *what = new char[whatStr.length() + 1];
    strncpy(what, whatStr.c_str(), whatStr.length() + 1);
    return what;
}