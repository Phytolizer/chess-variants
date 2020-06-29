#include "texture.hh"
#include <sdl_wrapper/render/weak_texture.hh>
#include <sdl_wrapper/sdl_exception.hh>
#include <sdl_wrapper/surface/surface.hh>

namespace sdl::render
{

Texture::Texture(WeakRenderer renderer, Uint32 pixelFormat, int access, int w, int h)
    : WeakTexture(SDL_CreateTexture(renderer.getHandle(), pixelFormat, access, w, h), w, h)
{
    if (handle == nullptr)
    {
        throw SDLException("creating texture from renderer");
    }
}

Texture::Texture(WeakRenderer renderer, surface::Surface &surface)
    : WeakTexture(SDL_CreateTextureFromSurface(renderer.getHandle(), surface.getHandle()), surface.getHandle()->w,
                  surface.getHandle()->h)
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

Texture::Texture(Texture &&other) : WeakTexture(other.handle, other.width, other.height)
{
    other.handle = nullptr;
}

Texture &Texture::operator=(Texture &&other)
{
    if (&other != this)
    {
        handle = other.handle;
        width = other.width;
        height = other.height;
        other.handle = nullptr;
    }
    return *this;
}
} // namespace sdl::render