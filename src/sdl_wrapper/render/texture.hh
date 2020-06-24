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
#include <sdl_wrapper/surface/surface.hh>

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
    /**
     * @brief Construct a new Texture with a specific pixel format, width, and height.
     * 
     * @param renderer a renderer, required to create textures
     * @param pixelFormat the pixel format to use
     * @param access the accessibility of the texture, use SDL_TEXTUREACCESS_TARGET to allow
     * drawing to this texture via renderer
     * @param w the texture's width in pixels
     * @param h the texture's height in pixels
     */
    Texture(Renderer &renderer, Uint32 pixelFormat, int access, int w, int h);
    /**
     * @brief Construct a new Texture using an existing Surface.
     * 
     * @param renderer a renderer, required to create textures
     * @param surface the surface to consume in creating this texture
     */
    Texture(Renderer &renderer, surface::Surface &surface);

    ~Texture();

    Texture(const Texture &) = delete;
    virtual Texture &operator=(const Texture &) = delete;

    /**
     * @brief move constructor
     * 
     * @param other the object to move from
     */
    Texture(Texture &&other);
    /**
     * @brief move assignment operator
     * 
     * @param other the object to move from
     * @return Texture& the object that was moved to
     */
    Texture &operator=(Texture &&other);
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_TEXTURE_HH