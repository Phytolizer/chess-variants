/**
 * @file context.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a wrapper for the SDL video subsystem
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_SDL_VIDEO_CONTEXT_HH
#define SDL_WRAPPER_SDL_VIDEO_CONTEXT_HH

#include <sdl_wrapper/video/window_builder.hh>

namespace sdl
{
// predeclaration, prevent recursive includes
class Context;
} // namespace sdl

namespace sdl::video
{

/**
 * @brief An RAII wrapper for the SDL video subsystem
 *
 */
class Context
{
  public:
    /**
     * @brief Initialize the SDL video subsystem. SDL must be initialized to do this.
     *
     */
    Context(::sdl::Context &);
    /**
     * @brief Initialize the SDL video subsystem using a specific driver. SDL must be
     * initialized to do this.
     *
     * @param driverName the driver to use
     */
    Context(::sdl::Context &, std::string_view driverName);

    ~Context();

    /// no copy constructor
    Context(const Context &) = delete;
    /// no copy assignment
    Context &operator=(const Context &) = delete;
    /**
     * @brief move constructor
     *
     * @param other the object to move from
     */
    Context(Context &&other);
    /**
     * @brief move assignment operator
     *
     * @param other the object to move from
     * @return Context& the object that was moved to
     */
    Context &operator=(Context &&other);

    /**
     * @brief Create a new window.
     *
     * @param title the window's title
     * @param x the window's x coordinate relative to the display's left side
     * @param y the window's y coordinate relative to the display's top side
     * @param w the width of the window's client area in pixels
     * @param h the height of the window's client area in pixels
     * @return WindowBuilder a builder to further configure the window before actually creating it
     */
    WindowBuilder createWindow(std::string_view title, int x, int y, int w, int h);

  private:
    /**
     * @brief Whether this video context is active, used to determine whether to call SDL_QuitSubSystem
     *
     */
    bool active;
    /**
     * @brief A hook that is called on destruction if the context is active.
     *
     */
    void (*onQuit)();
};
} // namespace sdl::video

#endif // SDL_WRAPPER_SDL_VIDEO_CONTEXT_HH