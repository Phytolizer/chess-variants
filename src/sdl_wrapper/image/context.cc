#include "context.hh"
#include <SDL_image/SDL_image.h>
#include <sdl_wrapper/image/img_exception.hh>

namespace sdl::image
{
Context::Context(InitFlags flags) : active(true)
{
    int initted = IMG_Init(static_cast<int>(flags));
    if ((initted & static_cast<int>(flags)) != static_cast<int>(flags))
    {
        throw IMGException("initializing SDL_image");
    }
}

Context::~Context()
{
    if (active)
    {
        IMG_Quit();
    }
}

Context::Context(Context &&other) : active(other.active)
{
    other.active = false;
}

Context &Context::operator=(Context &&other)
{
    if (&other != this)
    {
        active = other.active;
        other.active = false;
    }
    return *this;
}

surface::Surface Context::load(std::string_view fileName)
{
    SDL_Surface *handle = IMG_Load(fileName.data());
    if (handle == nullptr)
    {
        throw IMGException("loading image from file");
    }
    return surface::Surface(handle);
}
} // namespace sdl::image