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
 * @brief A weak reference to a Renderer. Used as a return value for SDL functions that
 * return references to existing renderers.
 * 
 */
class WeakRenderer
{
  public:
    WeakRenderer(SDL_Renderer *handle) __attribute__((nonnull(2)));
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
     * @brief Push the renderer's changes to the target
     *
     */
    void present() noexcept;

  protected:
    SDL_Renderer *handle;
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_WEAK_RENDERER_HH