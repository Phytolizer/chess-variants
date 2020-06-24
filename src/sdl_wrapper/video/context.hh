/**
 * @file sdl_video_context.hh
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
    Context(::sdl::Context &);
    Context(::sdl::Context &, std::string_view driverName);

    ~Context();

    /// no copy constructor
    Context(const Context &) = delete;
    /// no copy assignment
    Context &operator=(const Context &) = delete;
    Context(Context &&);
    Context &operator=(Context &&);

    WindowBuilder createWindow(std::string_view title, int x, int y, int w, int h);

  private:
    bool active;
    void (*onQuit)();
};
} // namespace sdl::video

#endif // SDL_WRAPPER_SDL_VIDEO_CONTEXT_HH