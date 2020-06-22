/**
 * @file window.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a memory-safe wrapper for the SDL_Window* datatype.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_VIDEO_WINDOW_HH
#define SDL_WRAPPER_VIDEO_WINDOW_HH

#include <SDL2/SDL_video.h>
#include <sdl_wrapper/render/renderer.hh>
#include <sdl_wrapper/render/renderer_builder.hh>
#include <string_view>

namespace sdl::video
{

class Context;
class Window
{
  public:
    Window(__attribute__((unused)) video::Context &context, std::string_view title, int x, int y, int w, int h,
           Uint32 flags);
    Window(SDL_Window *handle) __attribute__((nonnull(2)));

    ~Window();

    /// no copy constructor
    Window(const Window &) = delete;
    /// no copy assignment
    Window &operator=(const Window &) = delete;

    Window(Window &&other);
    Window &operator=(Window &&other);
    SDL_Window *getHandle() const;

    render::RendererBuilder createRenderer();

  private:
    SDL_Window *handle;
};
} // namespace sdl::video

#endif // SDL_WRAPPER_VIDEO_WINDOW_HH