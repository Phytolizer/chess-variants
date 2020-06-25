#include "renderer_builder.hh"
#include <sdl_wrapper/video/window.hh>

namespace sdl::render
{
RendererBuilder::RendererBuilder(video::WeakWindow &window) : windowHandle(window.getHandle()), index(-1), flags(0)
{
}

Renderer RendererBuilder::build()
{
    return Renderer(SDL_CreateRenderer(windowHandle, index, flags));
}

RendererBuilder &RendererBuilder::software()
{
    flags |= SDL_RENDERER_SOFTWARE;
    return *this;
}
RendererBuilder &RendererBuilder::accelerated()
{
    flags |= SDL_RENDERER_ACCELERATED;
    return *this;
}
RendererBuilder &RendererBuilder::presentVsync()
{
    flags |= SDL_RENDERER_PRESENTVSYNC;
    return *this;
}
RendererBuilder &RendererBuilder::targetTexture()
{
    flags |= SDL_RENDERER_TARGETTEXTURE;
    return *this;
}
RendererBuilder &RendererBuilder::driverIndex(int di)
{
    index = di;
    return *this;
}
} // namespace sdl::render