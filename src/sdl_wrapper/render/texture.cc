#include "texture.hh"
#include <sdl_wrapper/render/weak_texture.hh>
#include <sdl_wrapper/surface/surface.hh>
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

Texture::Texture(Renderer &renderer, surface::Surface &surface)
    : WeakTexture(SDL_CreateTextureFromSurface(renderer.getHandle(), surface.getHandle()))
{
    if (handle == nullptr)
    {
        throw SDLException("creating texture from surface");
    }
}

Texture::~Texture()
{
    if (handle != nullptr)
    {
        SDL_DestroyTexture(handle);
    }
}

} // namespace sdl::render