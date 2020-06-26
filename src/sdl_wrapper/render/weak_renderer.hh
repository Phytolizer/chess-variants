/**
 * @file weak_renderer.hh
 * @author your name (you@domain.com)
 * @brief Contains the WeakRenderer class
 * @date 2020-06-24
 */

#ifndef SDL_WRAPPER_RENDER_WEAK_RENDERER_HH
#define SDL_WRAPPER_RENDER_WEAK_RENDERER_HH

#include <SDL2/SDL_render.h>
#include <optional>
#include <sdl_wrapper/render/weak_texture.hh>
#include <vector>

namespace sdl::render
{
class Texture;

/**
 * @brief Hold the scaling factors that are returned from Renderer::getScale.
 *
 */
struct ScalingFactors
{
    /**
     * @brief The horizontal scaling factor.
     *
     */
    float scaleX;
    /**
     * @brief The vertical scaling factor.
     *
     */
    float scaleY;
};

/**
 * @brief A weak reference to a Renderer. Used as a return value for SDL functions that
 * return references to existing renderers.
 *
 */
class WeakRenderer
{
  public:
    /**
     * @brief Construct a new WeakRenderer from an existing handle. This is the
     * only way to construct WeakRenderers.
     *
     * @param handle the handle
     */
    WeakRenderer(SDL_Renderer *handle) __attribute__((nonnull(2)));
    /**
     * @brief Get the handle of this renderer reference.
     *
     * @return SDL_Renderer*
     */
    SDL_Renderer *getHandle() const;

    /**
     * @brief Get the number of render drivers for this machine.
     *
     * @return int the number of render drivers
     */
    static int getNumRenderDrivers();
    /**
     * @brief Get the draw blend mode for this renderer
     *
     * @return SDL_BlendMode the blend mode
     */
    SDL_BlendMode getDrawBlendMode() const;
    /**
     * @brief Get the drawing color for this renderer
     *
     * @return SDL_Color the color
     */
    SDL_Color getDrawColor() const;
    /**
     * @brief Get the driver info that this renderer uses
     *
     * @return SDL_RendererInfo the driver info object
     */
    SDL_RendererInfo getDriverInfo() const;
    /**
     * @brief Get the renderer's target as a weak reference
     *
     * @return WeakTexture the target
     */
    WeakTexture getTarget() const;
    /**
     * @brief Get information about this rendering context.
     *
     * @return SDL_RendererInfo
     */
    SDL_RendererInfo getInfo() const;
    /**
     * @brief Get the output size for the renderer.
     *
     * @return SDL_Rect the output size in pixels
     */
    SDL_Rect getOutputSize() const;

    /**
     * @brief Clear the renderer's target with its current
     * draw color
     */
    void clear();
    /**
     * @brief Copy a texture to the renderer's target
     *
     * @param texture the texture to copy
     * @param src the portion of the texture to copy, or std::nullopt
     * for the entire texture
     * @param dest the texture's destination rectangle, or std::nullopt
     * to copy to the entire render target
     */
    void copy(const Texture &texture, std::optional<SDL_Rect> src, std::optional<SDL_Rect> dest);
    /**
     * @brief Copy a texture to the renderer's target
     *
     * @param texture the texture to copy
     * @param src the portion of the texture to copy, or std::nullopt for the entire texture
     * @param dest the portion of the target to copy to, or std::nullopt for the entire target
     * @param angle the amount to rotate the texture by, in degrees clockwise
     * @param center the pivot to rotate around, or std::nullopt for the texture's geometric
     * center
     * @param flip the flipping action to perform on the texture
     */
    void copy(const Texture &texture, std::optional<SDL_Rect> src, std::optional<SDL_Rect> dest, double angle,
              std::optional<SDL_Point> center, SDL_RendererFlip flip);
    /**
     * @brief Set the drawing color for the renderer
     *
     * @param dc the draw color
     */
    void setDrawColor(SDL_Color dc);
    /**
     * @brief Draw a line on the target from point `p1` to `p2`
     *
     * @param p1 the point to start the line at
     * @param p2 the point where the line ends
     */
    void drawLine(SDL_Point p1, SDL_Point p2);
    /**
     * @brief Connect the dots to form lines. Each point will have a line drawn between
     * itself and the next point in the vector.
     *
     * @param vertices the points to connect
     */
    void drawLines(const std::vector<SDL_Point> &vertices);
    /**
     * @brief Draw a point to the target. Typically this draws a single
     * pixel.
     *
     * @param p the point to draw
     */
    void drawPoint(SDL_Point p);
    /**
     * @brief Draw all points to the target. See Renderer::drawPoint.
     *
     * @param points the points to draw
     */
    void drawPoints(const std::vector<SDL_Point> &points);
    /**
     * @brief Draw the outline of the rectangle defined by `r` to the target.
     * If you want a filled rectangle, see Renderer::fillRect.
     *
     * @param r the rectangle to draw
     */
    void drawRect(SDL_Rect r);
    /**
     * @brief Draw all rectangles contained in `rects` to the target.
     * See Renderer::drawRect.
     *
     * @param rects the rectangles to draw
     */
    void drawRects(const std::vector<SDL_Rect> &rects);
    /**
     * @brief Draw the rectangle defined by `r` filled in with the draw color
     * to the target. If you want just the outline, see Renderer::drawRect.
     *
     * @param r the rectangle to fill
     */
    void fillRect(SDL_Rect r);
    /**
     * @brief Draw all rectangles contained in `rects`, filled in, to the target.
     * See Renderer::fillRect.
     *
     * @param rects the rectangles to draw
     */
    void fillRects(const std::vector<SDL_Rect> &rects);
    /**
     * @brief Get the clip rectangle for the current render target. If clipping is disabled, returns an empty rectangle.
     *
     * @return SDL_Rect the clip
     */
    SDL_Rect getClip() const noexcept;
    /**
     * @brief Check if integer scale values are forced for resolution-independent rendering.
     *
     * @return true integer scales are forced
     * @return false integer scales are not forced
     */
    bool isIntegerScale() const;
    /**
     * @brief Get the logical size of this renderer, i.e. the device-independent resolution.
     *
     * @return SDL_Rect the logical size, x and y are always 0
     */
    SDL_Rect getLogicalSize() const noexcept;
    /**
     * @brief Get the drawing scale for the current render target.
     *
     * @return ScalingFactors the scale
     */
    ScalingFactors getScale() const noexcept;
    /**
     * @brief Get the drawing area on the current target. Viewports are used for things like minimaps.
     *
     * @return SDL_Rect the viewport
     */
    SDL_Rect getViewport() const noexcept;
    /**
     * @brief Check whether clipping is enabled for this renderer.
     *
     * @return true clipping is enabled
     * @return false clipping is disabled
     */
    bool isClipEnabled() const noexcept;
    /**
     * @brief Set the clip rectangle for rendering on the current target.
     *
     * @param clipRect the clip
     */
    void setClip(SDL_Rect clipRect);
    /**
     * @brief Set whether to force integer scales for resolution-independent rendering.
     *
     * @param forceIntegerScale the value
     */
    void setIntegerScale(bool forceIntegerScale);
    /**
     * @brief Set the device-independent resolution for rendering.
     *
     * @param size the size
     */
    void setLogicalSize(SDL_Rect size);
    /**
     * @brief Set the drawing scale for rendering on the current target.
     *
     * @param scale the scale
     */
    void setScale(ScalingFactors scale);
    /**
     * @brief Set the drawing area for rendering on the current target. This is useful for things such as minimaps where
     * part of the screen has its own coordinate system.
     *
     * @param viewport the viewport
     */
    void setViewport(SDL_Rect viewport);
    /**
     * @brief Check whether the window supports the use of render targets.
     *
     * @return true the window supports render targets
     * @return false the window does not support render targets
     */
    bool targetSupported() const noexcept;
    /**
     * @brief Set the blend mode used for drawing operations on this renderer. This affects how translucent objects
     * appear when layered on top of other objects.
     *
     * @param mode the blend mode
     */
    void setBlendMode(SDL_BlendMode mode);
    /**
     * @brief Set the current rendering target. This fails if the renderer was not created with texture targeting
     * enabled.
     *
     * @param texture the texture to target
     */
    void setTarget(WeakTexture texture);
    /**
     * @brief Set the current rendering target to the renderer's original target. Use this to stop rendering to a
     * texture.
     *
     */
    void resetTarget();
    /**
     * @brief Set an additional alpha multiplier used in render copy operations.
     *
     * @param alpha the alpha mod
     */
    void setAlphaMod(Uint8 alpha);
    /**
     * @brief Push the renderer's changes to the target
     *
     */
    void present() noexcept;

  protected:
    /**
     * @brief The SDL handle for the renderer it uses. It is used internally.
     *
     */
    SDL_Renderer *handle;
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_WEAK_RENDERER_HH