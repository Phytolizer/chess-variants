#include "weak_texture.hh"

namespace sdl::render
{

WeakTexture::WeakTexture(SDL_Texture *handle) : handle(handle)
{
}

SDL_Texture *WeakTexture::getHandle() const
{
    return handle;
}

} // namespace sdl::render