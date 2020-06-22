/**
 * @file texture.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a wrapper for the SDL_Texture* datatype.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_RENDER_TEXTURE_HH
#define SDL_WRAPPER_RENDER_TEXTURE_HH

#include <SDL2/SDL_render.h>
#include <sdl_wrapper/render/renderer.hh>
#include <sdl_wrapper/render/weak_texture.hh>

namespace sdl::render
{

class Renderer;

/**
 * @brief A memory-safe wrapper for the SDL_Texture* datatype
 * 
 */
class Texture : public WeakTexture
{
  public:
    Texture(Renderer &renderer, Uint32 pixelFormat, int access, int w, int h);

    ~Texture();

    Texture(const Texture &) = delete;
    virtual Texture &operator=(const Texture &) = delete;

    Texture(Texture &&other);
    Texture &operator=(Texture &&other);
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_TEXTURE_HH