/**
 * @file img_exception.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the IMGException class
 * @date 2020-06-25
 */

#ifndef SDL_WRAPPER_IMAGE_IMG_EXCEPTION_HH
#define SDL_WRAPPER_IMAGE_IMG_EXCEPTION_HH

#include <stdexcept>
#include <string_view>
#include <string>

namespace sdl::image
{
/**
 * @brief C++ version of an SDL_image error.
 *
 */
class IMGException : public std::runtime_error
{
  public:
    /**
     * @brief Construct a new IMGException object with the message 'message'.
     *
     * @param message the context of the error.
     */
    IMGException(std::string_view message);
    /**
     * @brief Get the user-friendly error message.
     *
     * @return const char* the error
     */
    virtual const char *what() const noexcept override;

  private:
    std::string message;
    std::string img_error;
};
} // namespace sdl::image

#endif // SDL_WRAPPER_IMAGE_IMG_EXCEPTION_HH