#include "weak_texture.hh"
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::render
{

WeakTexture::WeakTexture(SDL_Texture *handle) : handle(handle)
{
}

SDL_Texture *WeakTexture::getHandle() const
{
    return handle;
}

Uint8 WeakTexture::getAlphaMod() const
{
    Uint8 alphaMod;
    int code = SDL_GetTextureAlphaMod(handle, &alphaMod);
    if (code != 0)
    {
        throw SDLException("getting texture alpha mod");
    }
    return alphaMod;
}

SDL_BlendMode WeakTexture::getBlendMode() const
{
    SDL_BlendMode mode;
    int code = SDL_GetTextureBlendMode(handle, &mode);
    if (code != 0)
    {
        throw SDLException("getting texture blend mode");
    }
    return mode;
}

SDL_Color WeakTexture::getColorMod() const
{
    SDL_Color mod{0x00, 0x00, 0x00, 0xff};
    int code = SDL_GetTextureColorMod(handle, &mod.r, &mod.g, &mod.b);
    if (code != 0)
    {
        throw SDLException("getting texture color mod");
    }
    return mod;
}

} // namespace sdl::render