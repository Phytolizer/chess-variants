/**
 * @file weak_texture.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a class representing a weak reference to a SDL_Texture*.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_RENDER_WEAK_TEXTURE_HH
#define SDL_WRAPPER_RENDER_WEAK_TEXTURE_HH

#include <SDL2/SDL_render.h>

namespace sdl::render
{
class WeakTexture
{
  public:
    WeakTexture(SDL_Texture *handle);

    SDL_Texture *getHandle() const;

  protected:
    SDL_Texture *handle;
};
} // namespace sdl::render

#endif // SDL_WRAPPER_RENDER_WEAK_TEXTURE_HH