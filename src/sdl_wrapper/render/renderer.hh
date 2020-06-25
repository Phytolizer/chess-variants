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
#include <sdl_wrapper/render/weak_renderer.hh>
#include <vector>

namespace sdl::video
{
class WeakWindow;
}

/**
 * @namespace sdl::render
 * @brief Contains most classes and functions based on SDL_render.h
 * 
 */
namespace sdl::render
{

/**
 * @brief A memory-safe wrapper for the SDL_Renderer* datatype
 *
 */
class Renderer : public WeakRenderer
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
    Renderer(video::WeakWindow &window, int index, Uint32 flags);

    Renderer(SDL_Renderer *handle);
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    /**
     * @brief copy constructor
     * 
     * @param other the object to move from
     */
    Renderer(Renderer &&other);
    /**
     * @brief copy assignment operator
     * 
     * @param other the object to move from
     * @return Renderer& the object that was moved to
     */
    Renderer &operator=(Renderer &&other);
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_RENDERER_HH