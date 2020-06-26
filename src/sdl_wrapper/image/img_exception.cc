#include "img_exception.hh"
#include <SDL_image/SDL_image.h>
#include <sstream>
#include <util/util.hh>

namespace sdl::image
{
IMGException::IMGException(std::string_view message)
    : std::runtime_error(message.data()), message(message), img_error(IMG_GetError())
{
}

const char *IMGException::what() const noexcept
{
    std::string w;
    if (message.empty())
    {
        w = img_error;
    }
    else
    {
        w = util::concat(message, ": ", img_error);
    }
    char *what = new char[w.length() + 1];
    strncpy(what, w.c_str(), w.length() + 1);
    return what;
}
} // namespace sdl::image