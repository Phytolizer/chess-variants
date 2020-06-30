/**
 * @file mix_exception.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the MixException class for mixer errors
 * @date 2020-06-30
 */

#ifndef SDL_MIXER_MIX_EXCEPTION_HH
#define SDL_MIXER_MIX_EXCEPTION_HH

#include <stdexcept>
#include <string>
#include <string_view>

namespace sdl::mixer
{
/**
 * @brief Represents an error within SDL_mixer.
 */
class MixException : public std::runtime_error
{
  public:
    /**
     * @brief Construct a new MixException object with the given message.
     * @see what(), for formatting information
     *
     * @param message the context of the error
     */
    MixException(std::string_view message);
    /**
     * @brief Get the error message and mixer error. The format is, when message is nonempty:
     *
     * `<message>: <mix_error>`
     *
     * When message is empty, only the mixer error is printed.
     *
     * @return const char* the formatted message
     */
    const char *what() const noexcept override;

  private:
    std::string message;
    std::string mix_error;
    std::string what_str;
};
} // namespace sdl::mixer

#endif // SDL_MIXER_MIX_EXCEPTION_HH