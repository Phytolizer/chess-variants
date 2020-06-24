/**
 * @file window.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a memory-safe wrapper for the SDL_Window* datatype.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_VIDEO_WINDOW_HH
#define SDL_WRAPPER_VIDEO_WINDOW_HH

#include <SDL2/SDL_stdinc.h>
#include <sdl_wrapper/video/weak_window.hh>
#include <string_view>

namespace sdl::video
{

class Context;

/**
 * @brief A memory-safe wrapper for the SDL_Window* datatype
 */
class Window : public WeakWindow
{
  public:
    Window(video::Context &, std::string_view title, int x, int y, int w, int h, Uint32 flags);
    Window(const void *nativeData);

    ~Window();

    /// no copy constructor
    Window(const Window &) = delete;
    /// no copy assignment
    Window &operator=(const Window &) = delete;

    Window(Window &&other);
    Window &operator=(Window &&other);

  private:
};
} // namespace sdl::video

#endif // SDL_WRAPPER_VIDEO_WINDOW_HH