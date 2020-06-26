/**
 * @file weak_texture.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a class representing a weak reference to a SDL_Texture*.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_RENDER_WEAK_TEXTURE_HH
#define SDL_WRAPPER_RENDER_WEAK_TEXTURE_HH

#include <SDL2/SDL_render.h>
#include <tuple>

namespace sdl::render
{
/**
 * @brief A non-owning wrapper for the SDL_Texture* datatype
 */
class WeakTexture
{
  public:
    /**
     * @brief A sentinel value that states the width is unknown for this texture. It is set when the texture comes from
     * somewhere that cannot provide size data.
     *
     */
    static constexpr int WIDTH_UNKNOWN = 0;
    /**
     * @brief A sentinel value that states the height is unknown for this texture. It is set when the texture comes from
     * somewhere that cannot provide size data.
     *
     */
    static constexpr int HEIGHT_UNKNOWN = 0;

    /**
     * @brief Construct a weak texture from an existing handle.
     *
     * @param handle the handle
     * @param width the width in pixels
     * @param height the height in pixels
     */
    WeakTexture(SDL_Texture *handle, int width, int height);

    /**
     * @brief Get the internal handle used by this texture. Calling this function gets rid of
     * the Texture abstraction, in case you need an escape hatch.
     *
     * @return SDL_Texture* the internal handle
     */
    SDL_Texture *getHandle() const;

    /**
     * @brief Get the alpha multiplier used on copy operations for this texture.
     *
     * @return Uint8 the alpha mod
     */
    Uint8 getAlphaMod() const;

    /**
     * @brief Get the texture's blend mode used in copy operations.
     *
     * @return SDL_BlendMode the blend mode
     */
    SDL_BlendMode getBlendMode() const;

    /**
     * @brief Get the color multiplier used on copy operations for this texture.
     *
     * The alpha of the color returned will always be 255, see WeakTexture::getAlphaMod()
     * to read the alpha multiplier.
     *
     * @see WeakTexture::getAlphaMod()
     *
     * @return SDL_Color the color mod
     */
    SDL_Color getColorMod() const;

    /**
     * @brief Lock the texture for write-only access. Provide the `area` parameter
     * to only lock a certain area.
     *
     * @param area the area to lock
     * @return std::pair<void *, int> The void* is the pixel data; you can write here.
     * The int is the pitch, or number of bytes per row of the area locked.
     */
    std::pair<void *, int> lock(SDL_Rect area);

    /**
     * @brief Get the texture's width in pixels.
     *
     * @return int the width
     */
    int getWidth() const noexcept;

    /**
     * @brief Get the texture's height in pixels.
     *
     * @return int the height
     */
    int getHeight() const noexcept;

  protected:
    /**
     * @brief The internal SDL handle which the WeakTexture is abstracting over.
     *
     */
    SDL_Texture *handle;
    /**
     * @brief The width of the texture in pixels
     *
     */
    int width;
    /**
     * @brief The height of the texture in pixels
     *
     */
    int height;
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_WEAK_TEXTURE_HH