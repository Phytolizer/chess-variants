/**
 * @file sdl_exception.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a handy C++ wrapper for SDL error handling.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_SDL_EXCEPTION_HH
#define SDL_WRAPPER_SDL_EXCEPTION_HH

#include <stdexcept>
#include <string_view>

/**
 * @brief An exception for convenient reading of internal SDL errors
 */
class SDLException : public std::runtime_error
{
  public:
    /**
     * @brief Construct a new SDLException object with the message `message`.
     *
     * @param message The user-friendly message. Will be followed with ": " and then
     * the error reported by SDL.
     */
    SDLException(std::string_view message);

    /**
     * @brief Get the user-friendly error message as a whole.
     *
     * @return const char* a heap-allocated string holding the message
     * that the exception was constructed with, ": ", and then the SDL
     * error that was reported at construction time. If `message` is an
     * empty string, then only the SDL error will be printed.
     */
    const char *what() const noexcept override;

  private:
    std::string message;
    std::string sdl_error;
    std::string what_str;
};

#endif // SDL_WRAPPER_SDL_EXCEPTION_HH