/**
 * @file weak_window.hh
 * @author your name (you@domain.com)
 * @brief Contains the WeakWindow class
 * @date 2020-06-23
 */

#ifndef SDL_WRAPPER_VIDEO_WEAK_WINDOW_HH
#define SDL_WRAPPER_VIDEO_WEAK_WINDOW_HH

#include <SDL2/SDL_syswm.h>
#include <SDL2/SDL_video.h>
#include <array>
#include <sdl_wrapper/render/renderer_builder.hh>
#include <sdl_wrapper/surface/weak_surface.hh>
#include <string_view>

namespace sdl::video
{

/**
 * @brief The border sizes of a window.
 *
 */
struct WindowBordersSize
{
    /**
     * @brief The width of the top border decoration
     *
     */
    int top;
    /**
     * @brief The width of the left border decoration
     *
     */
    int left;
    /**
     * @brief The width of the bottom border decoration
     *
     */
    int bottom;
    /**
     * @brief The width of the right border decoration
     *
     */
    int right;
};

/**
 * @brief The gamma ramp for a display.
 * The gamma ramp is a translation table for red, green, and blue channels.
 */
struct GammaRamp
{
    /**
     * @brief The translation table for the red channel
     *
     */
    std::array<Uint16, 256> red;
    /**
     * @brief The translation table for the green channel
     *
     */
    std::array<Uint16, 256> green;
    /**
     * @brief The translation table for the blue channel
     *
     */
    std::array<Uint16, 256> blue;
};

/**
 * @brief A weak reference to an existing Window.
 *
 */
class WeakWindow
{
  public:
    /**
     * @brief Construct a WeakWindow from the existing handle `handle`.
     *
     * @param handle the handle
     */
    WeakWindow(SDL_Window *handle) __attribute__((nonnull(2)));
    /**
     * @brief Get the internal SDL window handle
     *
     * @return SDL_Window* the handle
     */
    SDL_Window *getHandle();

    // SDL functions

    /**
     * @brief Get the size of this window's borders (decorations).
     *
     * @return WindowBordersSize the border sizes
     * @throw sdl::SDLException if there is an SDL error
     */
    WindowBordersSize getBordersSize() const;

    /**
     * @brief Get the gamma multiplier for the display that owns this window.
     *
     * @return float the gamma from 0.0 to 1.0
     */
    float getBrightness() const noexcept;

    /**
     * @brief Get a pointer to this window's data.
     *
     * @param name the name of the data
     * @return void* the pointer
     */
    void *getDataPtr(std::string_view name) noexcept;

    /**
     * @brief Get the index of the display that owns this window.
     *
     * @return int the index
     * @throw sdl::SDLException if there is an SDL error
     */
    int getDisplayIndex() const;

    /**
     * @brief Get the display mode used when this window is fullscreen.
     *
     * @return SDL_DisplayMode the display mode
     * @throw sdl::SDLException if there is an SDL error
     */
    SDL_DisplayMode getDisplayMode() const;

    /**
     * @brief Get the flags that this window was created with.
     *
     * @return Uint32 the flags
     */
    Uint32 getFlags() const noexcept;

    /**
     * @brief Get the gamma ramp for the display that owns this window.
     *
     * @return GammaRamp the gamma ramp
     * @throw sdl::SDLException if there is an SDL error
     */
    GammaRamp getGammaRamp() const;

    /**
     * @brief Check the window's input grab.
     *
     * @return true the window has input focus
     * @return false the window does not have input focus
     */
    bool isGrabbed() const noexcept;

    /**
     * @brief Get the window's ID for logging purposes.
     *
     * @return Uint32 the window ID
     * @throw sdl::SDLException if there is an SDL error
     */
    Uint32 getId() const;

    /**
     * @brief Get the maximum size of the window's client area.
     *
     * @return SDL_Rect the maximum size; x and y will always be 0
     */
    SDL_Rect getMaxSize() const noexcept;

    /**
     * @brief Get the minimum size of the window's client area.
     *
     * @return SDL_Rect the minimum size; x and y will always be 0
     */
    SDL_Rect getMinSize() const noexcept;

    /**
     * @brief Get the window's opacity. If opacity is not supported, this returns 1.
     *
     * @return float the opacity, from 0.0 to 1.0
     */
    float getOpacity() const;

    /**
     * @brief Get the pixel format that this Window is configured with.
     *
     * @return Uint32 the pixel format, one of the SDL_PixelFormatEnum variants
     * @throw sdl::SDLException if there is an SDL error
     */
    Uint32 getPixelFormat() const;

    /**
     * @brief Get the window's position on the display.
     *
     * @return SDL_Point the position
     */
    SDL_Point getPosition() const noexcept;

    /**
     * @brief Get the window's size in pixels.
     *
     * @return SDL_Rect the size
     */
    SDL_Rect getSize() const noexcept;

    /**
     * @brief Create a surface tied to the window.
     *
     * @return WeakSurface the surface. It is a WeakSurface because it should not be freed;
     * SDL frees it automatically when the window is destroyed.
     * @throw sdl::SDLException if there is an SDL error
     */
    surface::WeakSurface getSurface();

    /**
     * @brief Get the window's title.
     *
     * @return std::string the title
     */
    std::string getTitle() const noexcept;

    /**
     * @brief Get driver-specific information about this window.
     *
     * @return SDL_SysWMinfo the info
     */
    SDL_SysWMinfo getWmInfo() const;

    /**
     * @brief Hides the window.
     *
     */
    void hide() noexcept;

    /**
     * @brief Maximizes the window.
     *
     */
    void maximize() noexcept;

    /**
     * @brief Minimizes the window.
     *
     */
    void minimize() noexcept;

    /**
     * @brief Raises the window and gives it input focus.
     *
     */
    void raise() noexcept;

    /**
     * @brief Restores a window, removing its minimized/maximized state.
     *
     */
    void restore() noexcept;

    /**
     * @brief Set whether the window has a border (decorations).
     *
     * @param bordered whether it should be bordered
     */
    void setHasBorder(bool bordered) noexcept;

    /**
     * @brief Set the window's brightness.
     *
     * @param brightness the brightness, from 0.0 to 1.0
     * @throw sdl::SDLException if there is an SDL error
     */
    void setBrightness(float brightness);

    /**
     * @brief Store arbitrary data in the window using a name.
     *
     * @param name the name to use
     * @param data the data to store
     * @return void* the previous data stored under `name`
     */
    void *setData(std::string_view name, void *data);

    /**
     * @brief Sets the display mode for this window.
     *
     * @param mode the display mode
     * @throw sdl::SDLException if there is an SDL error
     */
    void setDisplayMode(const SDL_DisplayMode &mode);

    /**
     * @brief Set the window to a fullscreen video mode.
     *
     * See Window::setFullscreenDesktop for 'fake' fullscreen.
     *
     * @throw sdl::SDLException if there is an SDL error
     */
    void setFullscreen();

    /**
     * @brief Set the window to a 'fake' fullscreen mode. The desktop's video mode is still used.
     *
     * See Window::setFullscreen for 'true' fullscreen.
     *
     * @throw sdl::SDLException if there is an SDL error
     */
    void setFullscreenDesktop();

    /**
     * @brief Set the window to windowed mode, if it was in fullscreen or fullscreen desktop.
     *
     * @throw sdl::SDLException if there is an SDL error
     */
    void setWindowed();

    /**
     * @brief Set the window's display's gamma ramp.
     *
     * @param ramp the gamma ramp
     * @throw sdl::SDLException if there is an SDL error
     */
    void setGammaRamp(const GammaRamp &ramp);

    /**
     * @brief Set the window's input grab state.
     *
     * @param grabbed whether to grab input
     */
    void setInputGrabbed(bool grabbed) noexcept;

    /**
     * @brief Set a callback for hit testing functionality.
     * Hit testing is useful for making parts of a window draggable other than its decorations.
     *
     * @param callback the function to call when hit testing
     * @param callbackData the data to pass to the function
     * @throw sdl::SDLException if there is an SDL error
     */
    void setHitTest(SDL_HitTest callback, void *callbackData);

    /**
     * @brief Set the window's icon.
     *
     * @param icon the icon
     */
    void setIcon(surface::WeakSurface icon) noexcept;

    /**
     * @brief Give the window input focus explicitly.
     *
     * @throw sdl::SDLException if there is an SDL error
     */
    void setAsFocus();

    /**
     * @brief Set the window's maximum size.
     *
     * @param maxSize the max size. `x` and `y` are ignored.
     */
    void setMaxSize(SDL_Rect maxSize) noexcept;

    /**
     * @brief Set the window's minimum size.
     *
     * @param minSize the min size. `x` and `y` are ignored.
     */
    void setMinSize(SDL_Rect minSize) noexcept;

    /**
     * @brief Set the window to be a modal for a parent window.
     *
     * @param parent the parent window
     * @throw sdl::SDLException if there is an SDL error
     */
    void setAsModalFor(WeakWindow parent);

    /**
     * @brief Set the window's opacity.
     *
     * @param opacity the opacity, from 0.0 to 1.0
     * @throw sdl::SDLException if there is an SDL error
     */
    void setOpacity(float opacity);

    /**
     * @brief Set the window's position relative to the display's upper left corner.
     *
     * @param position the position
     */
    void setPosition(SDL_Point position) noexcept;

    /**
     * @brief Set whether the window is resizable by a user.
     *
     * @param resizable whether it is resizable
     */
    void setResizable(bool resizable) noexcept;

    /**
     * @brief Set the window's client area size.
     *
     * @param size the size
     */
    void setSize(SDL_Rect size) noexcept;

    /**
     * @brief Set the window's title.
     *
     * @param title the title
     */
    void setTitle(std::string_view title) noexcept;

    /**
     * @brief Update the window's surface, pushing changes to the screen.
     *
     * @throw sdl::SDLException if there is an SDL error
     */
    void updateSurface();

    /**
     * @brief Like WeakWindow::updateSurface(), but only update the specified areas
     * of the surface.
     *
     * @param areas an array of SDL_Rects specifying the areas to update
     */
    void updateSurfaceAreas(std::vector<SDL_Rect> areas);

    /**
     * @brief Get the Renderer associated with this window.
     *
     * @return render::WeakRenderer the renderer
     * @throw sdl::SDLException if there is an SDL error
     */
    render::WeakRenderer getRenderer();

    // Spawning functions

    /**
     * @brief Create a Renderer via a RendererBuilder. See render::RendererBuilder for detauls.
     *
     * @return render::RendererBuilder the builder for a new Renderer attached to this window
     */
    render::RendererBuilder createRenderer();

  protected:
    /**
     * @brief The internal SDL handle that this window abstracts over
     *
     */
    SDL_Window *handle;
};
} // namespace sdl::video

#endif // SDL_WRAPPER_VIDEO_WEAK_WINDOW_HH