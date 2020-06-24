/**
 * @file video.hh
 * @author your name (you@domain.com)
 * @brief Contains the Display class and miscellaneous video-related free functions
 * @date 2020-06-23
 */

/**
 * @dir video
 * This directory contains all `sdl::video` classes and functions.
 */

#ifndef SDL_WRAPPER_VIDEO_VIDEO_HH
#define SDL_WRAPPER_VIDEO_VIDEO_HH

#include <SDL2/SDL_video.h>
#include <optional>
#include <sdl_wrapper/video/weak_window.hh>
#include <sdl_wrapper/video/window.hh>
#include <string>

/**
 * @namespace sdl::video
 * @brief This namespace roughly corresponds to SDL_video.h in that it defines
 * most functions in that file.
 *
 */
namespace sdl::video
{
/**
 * @brief Represents the DPI of a display in three directions.
 *
 */
struct Dpi
{
    float diag;
    float horz;
    float vert;
};

/**
 * @brief An abstraction over a single display on the host system. Has an index that is
 * used for all of its methods.
 *
 * @see video::getNumDisplays()
 *
 */
struct Display
{
    int index;

    /**
     * @brief Get the number of display modes this display supports.
     *
     * @return int the number of display modes
     * @throw sdl::SDLException if there is an SDL error
     */
    int getNumModes();
    /**
     * @brief Get the closest display mode that this display supports to the one provided.
     *
     * @param mode the desired display mode
     * @return SDL_DisplayMode the closest display mode to `mode`
     * @throw sdl::SDLException if there is an SDL error
     */
    SDL_DisplayMode getClosestMode(const SDL_DisplayMode &mode);
    /**
     * @brief Get the current display mode of the display.
     *
     * @return SDL_DisplayMode the current display mode
     * @throw sdl::SDLException if there is an SDL error
     */
    SDL_DisplayMode getCurrentMode();
    /**
     * @brief Get the display mode of the desktop environment.
     *
     * @return SDL_DisplayMode the desktop's display mode
     * @throw sdl::SDLException if there is an SDL error
     */
    SDL_DisplayMode getDesktopDisplayMode();
    /**
     * @brief Get the boundaries of this display. X and Y coordinates represent the offset in pixels from the
     * top-left-most display.
     *
     * @return SDL_Rect the display bounds
     * @throw sdl::SDLException if there is an SDL error
     */
    SDL_Rect getBounds();
    /**
     * @brief Get the DPI of this display. See sdl::video::Dpi.
     *
     * @return Dpi the display's DPI
     * @throw sdl::SDLException if there is an SDL error
     */
    Dpi getDpi();
    /**
     * @brief Get more detailed information about the display mode at `modeIndex`.
     *
     * @param modeIndex the mode's index within this display
     * @return SDL_DisplayMode the object corresponding to the index
     * @throw sdl::SDLException if there is an SDL error
     */
    SDL_DisplayMode getModeInfo(int modeIndex);
    /**
     * @brief Get the display's name.
     *
     * @return std::string the name of the display
     * @throw sdl::SDLException if there is an SDL error
     */
    std::string getName();
    /**
     * @brief Get the usable desktop area within the display's bounds. This is at most the size
     * returned by Display::getBounds().
     *
     * @return SDL_Rect the usable desktop area
     * @throw sdl::SDLException if there is an SDL error
     */
    SDL_Rect getUsableBounds();
};

/**
 * @brief Enables screen savers on the machine.
 *
 */
void enableScreenSaver() noexcept;

/**
 * @brief Disables screen savers on the machine.
 * They will automatically be re-enabled when SDL quits.
 */
void disableScreenSaver() noexcept;

/**
 * @brief Tell whether the screen saver is enabled by SDL.
 *
 * @return true the screen saver is enabled
 * @return false the screen saver is disabled
 */
bool isScreenSaverEnabled() noexcept;

/**
 * @brief Get the current video driver used by the system.
 *
 * @return std::string the current video driver's name
 * @throw sdl::SDLException if there is an SDL error
 */
std::string getCurrentVideoDriver();
/**
 * @brief Get the WeakWindow representing the Window that currently has input focus.
 *
 * @return std::optional<WeakWindow> a reference to the existing Window, or std::nullopt if input is not grabbed
 */
std::optional<WeakWindow> getGrabbedWindow() noexcept;
/**
 * @brief Get the number of displays connected to the system.
 *
 * @return int the number of displays
 * @throw sdl::SDLException if there is an SDL error
 */
int getNumDisplays();
/**
 * @brief Get the number of video drivers supported by the system.
 *
 * @return int the number of video drivers
 * @throw sdl::SDLException if there is an SDL error
 */
int getNumVideoDrivers();
/**
 * @brief Get the video driver at `index`.
 *
 * @param index the index, see sdl::video::getNumVideoDrivers().
 * @return std::string the name of the video driver
 * @throw sdl::SDLException if there is an SDL error
 */
std::string getVideoDriver(int index);
/**
 * @brief Get the window associated with `id` as a weak reference.
 *
 * @param id the window's ID
 * @return WeakWindow the window
 * @throw sdl::SDLException if the window doesn't exist
 */
WeakWindow getWindowFromId(Uint32 id);
/**
 * @brief Initialize the SDL video subsystem. You can specify a driver to use here.
 *
 * @throw sdl::SDLException if there is an SDL error
 */
void init(std::optional<std::string_view> driverName);

/**
 * @brief Quit the SDL video subsystem. Closes all windows and restores the original video mode.
 *
 */
void quit() noexcept;

/**
 * @brief Create a Window and Renderer in tandem. The Renderer is owned by the Window.
 *
 * @param width the width of the window's client area
 * @param height the height of the window's client area
 * @param windowFlags the flags to use for the window
 * @return std::pair<Window, render::Renderer> the window and renderer, use std::tie or std::get to access
 */
std::pair<Window, render::Renderer> createWindowAndRenderer(int width, int height, Uint32 windowFlags);
} // namespace sdl::video

#endif // SDL_WRAPPER_VIDEO_VIDEO_HH