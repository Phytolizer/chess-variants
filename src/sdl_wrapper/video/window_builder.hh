/**
 * @file window_builder.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a builder class for sdl::video::Window.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_VIDEO_WINDOW_BUILDER_HH
#define SDL_WRAPPER_VIDEO_WINDOW_BUILDER_HH

#include <sdl_wrapper/video/window.hh>
#include <string_view>

namespace sdl::video
{
/**
 * @brief A builder for the sdl::video::Window class
 */
class WindowBuilder
{
  public:
    WindowBuilder(__attribute__((unused)) video::Context &context, std::string_view title, int x, int y, int w, int h);
    Window build();

    WindowBuilder &fullscreen();
    WindowBuilder &fullscreenDesktop();
    WindowBuilder &openGl();
    WindowBuilder &vulkan();
    WindowBuilder &hidden();
    WindowBuilder &borderless();
    WindowBuilder &resizable();
    WindowBuilder &minimized();
    WindowBuilder &maximized();
    WindowBuilder &inputGrabbed();
    WindowBuilder &allowHighDpi();
    WindowBuilder &positionCentered();

  private:
    Uint32 flags;

    std::string_view title;
    int x;
    int y;
    int w;
    int h;
};
} // namespace sdl::video

#endif // SDL_WRAPPER_VIDEO_WINDOW_BUILDER_HH