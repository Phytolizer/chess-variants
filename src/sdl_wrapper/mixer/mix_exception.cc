#include "mix_exception.hh"
#include <SDL2/SDL_mixer.h>
#include <util/util.hh>

namespace sdl::mixer
{
MixException::MixException(std::string_view message)
    : std::runtime_error(message.data()), message(message), mix_error(Mix_GetError())
{
    if (message.empty())
    {
        what_str = util::concat(message, ": ", mix_error);
    }
    else
    {
        what_str = mix_error;
    }
}

const char *MixException::what() const noexcept
{
    return what_str.c_str();
}
} // namespace sdl::mixer