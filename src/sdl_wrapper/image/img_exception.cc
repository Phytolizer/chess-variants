#include "img_exception.hh"
#include <SDL_image/SDL_image.h>
#include <sstream>
#include <util/util.hh>

namespace sdl::image
{
IMGException::IMGException(std::string_view message)
    : std::runtime_error(message.data()), message(message), img_error(IMG_GetError())
{
    if (message.empty())
    {
        what_str = img_error;
    }
    else
    {
        what_str = util::concat(message, ": ", img_error);
    }
}

const char *IMGException::what() const noexcept
{
    return what_str.c_str();
}
} // namespace sdl::image