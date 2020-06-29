/**
 * @file context.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the image::Context class
 * @date 2020-06-25
 */

#ifndef SDL_WRAPPER_IMAGE_CONTEXT_HH
#define SDL_WRAPPER_IMAGE_CONTEXT_HH

#include <sdl_wrapper/image/image.hh>
#include <sdl_wrapper/surface/surface.hh>
#include <string_view>

namespace sdl::image
{
/**
 * @brief A representation of SDL_image's active state. IMG_Quit will be called on its destruction.
 *
 */
class Context
{
  public:
    /**
     * @brief Initialize SDL_image with the provided InitFlags.
     *
     * @param flags the components of SDL_image to initialize
     */
    Context(InitFlags flags);
    ~Context();
    Context(const Context &) = delete;
    Context &operator=(const Context &) = delete;
    /**
     * @brief move constructor
     *
     * @param other the object to move from
     */
    Context(Context &&other) noexcept;
    /**
     * @brief move assignment operator
     *
     * @param other the object to move from
     * @return Context& the object that was moved to
     */
    Context &operator=(Context &&other) noexcept;

    /**
     * @brief Load an image to a surface for use in the program.
     *
     * @param fileName the image file to load
     * @return surface::Surface the image as a Surface
     */
    surface::Surface load(std::string_view fileName);

  private:
    /**
     * @brief The active state of this context. Only one context should be active at a time.
     *
     */
    bool active;
};
} // namespace sdl::image

#endif // SDL_WRAPPER_IMAGE_CONTEXT_HH