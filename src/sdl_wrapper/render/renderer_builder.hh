/**
 * @file renderer_builder.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a builder for the sdl::render::Renderer class.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_RENDER_RENDERER_BUILDER_HH
#define SDL_WRAPPER_RENDER_RENDERER_BUILDER_HH

#include <sdl_wrapper/render/renderer.hh>

namespace sdl::render
{
/**
 * @brief A builder for the sdl::render::Renderer class
 * 
 */
class RendererBuilder
{
  public:
    RendererBuilder(video::Window &window);

    Renderer build();

    RendererBuilder &software();
    RendererBuilder &accelerated();
    RendererBuilder &presentVsync();
    RendererBuilder &targetTexture();
    RendererBuilder &driverIndex(int di);

  private:
    SDL_Window *windowHandle;
    int index;
    Uint32 flags;
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_RENDERER_BUILDER_HH