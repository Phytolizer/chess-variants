/**
 * @file renderer.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a wrapper for the SDL_Render... free functions as a class
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_RENDER_RENDERER_HH
#define SDL_WRAPPER_RENDER_RENDERER_HH

#include <SDL2/SDL_render.h>
#include <sdl_wrapper/render/weak_texture.hh>

namespace sdl::video
{
class Window;
}

namespace sdl::render
{

class Texture;

class Renderer
{
  public:
    Renderer(video::Window &window, int index, Uint32 flags);
    Renderer(SDL_Renderer *handle) __attribute__((nonnull(2)));
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    Renderer(Renderer &&other);
    Renderer &operator=(Renderer &&other);

    static int getNumRenderDrivers();
    SDL_BlendMode getDrawBlendMode() const;
    SDL_Color getDrawColor() const;
    SDL_RendererInfo getDriverInfo() const;
    WeakTexture getTarget() const;

    void clear();
    void copy(const Texture &texture, SDL_Rect src, SDL_Rect dest);
    void copy(const Texture &texture, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point center,
              SDL_RendererFlip flip);
    void present();

    SDL_Renderer *getHandle() const;

  private:
    SDL_Renderer *handle;
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_RENDERER_HH