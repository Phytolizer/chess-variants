/**
 * @file renderer_builder.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a builder for the sdl::render::Renderer class.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_RENDER_RENDERER_BUILDER_HH
#define SDL_WRAPPER_RENDER_RENDERER_BUILDER_HH

#include <sdl_wrapper/render/renderer.hh>

namespace sdl::video
{
class WeakWindow;
}

namespace sdl::render
{
/**
 * @brief A builder for the sdl::render::Renderer class
 *
 */
class RendererBuilder
{
  public:
    /**
     * @brief Construct a new renderer builder with its owning window.
     * You should follow this up with a chain of method calls to configure the renderer, followed
     * by a call to build().
     * 
     * @param window 
     */
    RendererBuilder(video::WeakWindow &window);

    /**
     * @brief Finish building the renderer.
     * 
     * @return Renderer the renderer that was built
     */
    Renderer build();

    /**
     * @brief Use software rendering for this renderer.
     * 
     * @return RendererBuilder& the builder
     */
    RendererBuilder &software();
    /**
     * @brief Use hardware-accelerated rendering for the renderer.
     * 
     * @return RendererBuilder& the builder
     */
    RendererBuilder &accelerated();
    /**
     * @brief Force this renderer to present with vertical sync.
     * 
     * @return RendererBuilder& the builder
     */
    RendererBuilder &presentVsync();
    /**
     * @brief Allow this renderer to use a texture as a target.
     * 
     * @return RendererBuilder& the builder
     */
    RendererBuilder &targetTexture();
    /**
     * @brief Use the driver at `index` for this renderer.
     *
     * @see sdl::video::getNumVideoDrivers()
     * 
     * @param di the driver index
     * @return RendererBuilder& the builder
     */
    RendererBuilder &driverIndex(int di);

  private:
    /**
     * @brief The parent window's handle. Used in build().
     * 
     */
    SDL_Window *windowHandle;
    /**
     * @brief The driver index to use. Used in build() and set in driverIndex().
     * 
     */
    int index;
    /**
     * @brief Other flags for the renderer. Used in build() and set by most builder methods.
     * 
     */
    Uint32 flags;
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_RENDERER_BUILDER_HH