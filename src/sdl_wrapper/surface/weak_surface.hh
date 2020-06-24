/**
 * @file weak_surface.hh
 * @author your name (you@domain.com)
 * @brief Contains the WeakSurface class
 * @date 2020-06-23
 */

#ifndef SDL_WRAPPER_SURFACE_WEAK_SURFACE_HH
#define SDL_WRAPPER_SURFACE_WEAK_SURFACE_HH

#include "SDL2/SDL_surface.h"
#include <optional>

namespace sdl::surface
{
/**
 * @brief A weak (non-owning) reference to a Surface. Used for SDL functions that return
 * a reference to an existing surface, or as a parameter to similar functions.
 *
 */
class WeakSurface
{
  public:
    /**
     * @brief Construct a weak surface from an existing SDL handle.
     *
     * @param handle the handle
     */
    WeakSurface(SDL_Surface *handle) __attribute__((nonnull(2)));
    /**
     * @brief Get the internal handle which this surface abstracts over.
     *
     * @return SDL_Surface* the handle
     */
    SDL_Surface *getHandle() const;

    /**
     * @brief Perform a scaled copy to another surface.
     *
     * @param clip the part of this surface to copy
     * @param dest the surface to copy to
     * @param destRect the part of the destination to copy to
     */
    void blitScaledTo(std::optional<SDL_Rect> clip, WeakSurface dest, std::optional<SDL_Rect> destRect);

    /**
     * @brief Perform a fast copy to another surface.
     * 
     * @param clip the part of this surface to copy
     * @param dest the surface to copy to
     * @param destRect the part of the destination to copy to
     */
    void blitTo(std::optional<SDL_Rect> clip, WeakSurface dest, std::optional<SDL_Rect> destRect);

    /**
    * @brief Copy a surface into a new one that is optimized for a particular pixel format.
    * 
    * @param src the original surface
    * @param fmt the pixel format to optimize the new surface for
    * @return Surface the new surface
    */
    Surface convertSurface(const SDL_PixelFormat &fmt);

  protected:
    /**
     * @brief The internal SDL handle which this surface abstracts over
     *
     */
    SDL_Surface *handle;
};
} // namespace sdl::surface

#endif // SDL_WRAPPER_SURFACE_WEAK_SURFACE_HH