/**
 * @file renderer.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a wrapper for the SDL_Render... free functions as a class
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_RENDER_RENDERER_HH
#define SDL_WRAPPER_RENDER_RENDERER_HH

#include <SDL2/SDL_render.h>
#include <optional>
#include <sdl_wrapper/render/weak_texture.hh>

namespace sdl::video
{
class Window;
}

namespace sdl::render
{

class Texture;

/**
 * @brief A memory-safe wrapper for the SDL_Renderer* datatype
 *
 */
class Renderer
{
  public:
    /**
     * @brief Construct a new Renderer object using a window
     * and user-specified options
     *
     * @param window the window which owns the Renderer
     * @param index the renderer driver to use, or -1 to automatically
     * pick one
     * @param flags the flags to use. If you don't know what these are,
     * use sdl::render::RendererBuilder instead.
     */
    Renderer(video::Window &window, int index, Uint32 flags);

    /**
     * @brief Construct a new Renderer object directly
     * from an existing SDL_Renderer* pointer.
     *
     * @param handle the pointer to take ownership of
     *
     */
    Renderer(SDL_Renderer *handle) __attribute__((nonnull(2)));
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    Renderer(Renderer &&other);
    Renderer &operator=(Renderer &&other);

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
    void copy(const Texture &texture, std::optional<SDL_Rect> src, std::optional<SDL_Rect> dest, double angle,
              std::optional<SDL_Point> center, SDL_RendererFlip flip);
    void present();

    SDL_Renderer *getHandle() const;

  private:
    SDL_Renderer *handle;
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_RENDERER_HH