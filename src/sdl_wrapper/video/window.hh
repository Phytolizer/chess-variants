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
    /**
     * @brief Construct a new Window with a specified title, coordinates, size, and flags.
     * @see WindowBuilder
     * 
     * @param title the window's title
     * @param x the window's x coordinate
     * @param y the window's y coordinate
     * @param w the window's width
     * @param h the window's height
     * @param flags the window's flags
     */
    Window(video::Context &, std::string_view title, int x, int y, int w, int h, Uint32 flags);
    /**
     * @brief Construct a new Window from an existing native window. This function is very dangerous.
     * 
     * @param nativeData the data from the native window
     */
    Window(const void *nativeData);

    ~Window();

    /// no copy constructor
    Window(const Window &) = delete;
    /// no copy assignment
    Window &operator=(const Window &) = delete;

    /**
     * @brief copy constructor
     * 
     * @param other the object to move from
     */
    Window(Window &&other);
    /**
     * @brief copy assignment operator
     * 
     * @param other the object to move from
     * @return Window& the object that was moved to
     */
    Window &operator=(Window &&other);

  private:
};
} // namespace sdl::video

#endif // SDL_WRAPPER_VIDEO_WINDOW_HH