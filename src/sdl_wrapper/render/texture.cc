#include "texture.hh"
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::render
{

Texture::Texture(Renderer &renderer, Uint32 pixelFormat, int access, int w, int h)
    : WeakTexture(SDL_CreateTexture(renderer.getHandle(), pixelFormat, access, w, h))
{
    if (handle == nullptr)
    {
        throw SDLException("creating texture from renderer");
    }
}

} // namespace sdl::render