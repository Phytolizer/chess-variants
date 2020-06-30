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
#include <vector>

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
     * @brief Fill a rectangle of the surface with a color.
     *
     * @param rect the area to fill
     * @param color the color to fill in
     */
    void fillRect(SDL_Rect rect, SDL_Color color);

    /**
     * @brief Fill some areas of a surface with a color.
     *
     * @param rects the areas to fill
     * @param color the color to fill in
     */
    void fillRects(std::vector<SDL_Rect> rects, SDL_Color color);

    /**
     * @brief Get the clip that is used for this surface.
     * The surface's clip is the area that is drawable within a surface.
     *
     * @return SDL_Rect the clip
     */
    SDL_Rect getClip() const noexcept;

    /**
     * @brief Get the color key for this surface.
     *
     * @return SDL_Color the color key
     */
    SDL_Color getColorKey() const;

    /**
     * @brief Get the alpha multiplier for this surface.
     *
     * @return Uint8 the alpha mod
     */
    Uint8 getAlphaMod() const;

    /**
     * @brief Get the blending mode for this surface.
     *
     * @return SDL_BlendMode the blend mode
     */
    SDL_BlendMode getBlendMode() const;

    /**
     * @brief Get the color multiplier used when this surface is blit.
     *
     * @return SDL_Color the color mod
     */
    SDL_Color getColorMod() const;

    /**
     * @brief Lock the surface for direct pixel access.
     *
     */
    void lock();

    /**
     * @brief Unlock the surface, disables direct pixel access.
     *
     */
    void unlock() noexcept;

  protected:
    /**
     * @brief Set the internal handle.
     *
     * @param handle the new handle
     */
    void setHandle(SDL_Surface *handle);

  private:
    /**
     * @brief The internal SDL handle which this surface abstracts over
     *
     */
    SDL_Surface *handle;
};
} // namespace sdl::surface

#endif // SDL_WRAPPER_SURFACE_WEAK_SURFACE_HH