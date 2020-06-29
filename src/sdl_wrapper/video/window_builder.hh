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
    /**
     * @brief Begin constructing a new Window with a specified title, position, and size.
     *
     * @param title the window's title
     * @param x the window's x coordinate
     * @param y the window's y coordinate
     * @param w the window's width
     * @param h the window's height
     */
    WindowBuilder(video::Context &, std::string_view title, int x, int y, int w, int h);
    /**
     * @brief Finish constructing the new Window.
     *
     * @return Window the window that was constructed
     */
    Window build();

    /**
     * @brief Set the window to fullscreen.
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &fullscreen();
    /**
     * @brief Set the window to "fake" fullscreen, which is more like a borderless window.
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &fullscreenDesktop();
    /**
     * @brief Set the window to use the OpenGL API.
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &openGl();
    /**
     * @brief Set the window to use the Vulkan API.
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &vulkan();
    /**
     * @brief Set the window to be hidden.
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &hidden();
    /**
     * @brief Set the window to have no border decorations.
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &borderless();
    /**
     * @brief Set the window to be user-resizable.
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &resizable();
    /**
     * @brief Set the window to be minimized.
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &minimized();
    /**
     * @brief Set the window to be maximized.
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &maximized();
    /**
     * @brief Set the window to have input grabbed (i.e. can't move the mouse out).
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &inputGrabbed();
    /**
     * @brief Create the window in high-DPI mode (if supported).
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &allowHighDpi();
    /**
     * @brief Set the window to be centered on the display.
     *
     * @return WindowBuilder& the builder
     */
    WindowBuilder &positionCentered();

  private:
    /**
     * @brief The flags that are used in the call to SDL_CreateWindow.
     *
     */
    Uint32 flags;

    /**
     * @brief The window's title
     *
     */
    std::string_view title;
    /**
     * @brief The window's x coordinate
     *
     */
    int x;
    /**
     * @brief The window's y coordinate
     *
     */
    int y;
    /**
     * @brief The window's width
     *
     */
    int w;
    /**
     * @brief The window's height
     *
     */
    int h;
};
} // namespace sdl::video

#endif // SDL_WRAPPER_VIDEO_WINDOW_BUILDER_HH