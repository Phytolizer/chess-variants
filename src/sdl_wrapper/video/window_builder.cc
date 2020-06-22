#include "window_builder.hh"
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::video
{
WindowBuilder::WindowBuilder(__attribute__((unused)) video::Context &context, std::string_view title, int x, int y,
                             int w, int h)
    : flags(0), title(title), x(x), y(y), w(w), h(h)
{
}
Window WindowBuilder::build()
{
    SDL_Window *handle = SDL_CreateWindow(title.data(), x, y, w, h, flags);
    if (handle == nullptr)
    {
        throw SDLException("creating window");
    }
    return Window(handle);
}

WindowBuilder &WindowBuilder::fullscreen()
{
    flags |= SDL_WINDOW_FULLSCREEN;
    return *this;
}
WindowBuilder &WindowBuilder::fullscreenDesktop()
{
    flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    return *this;
}
WindowBuilder &WindowBuilder::openGl()
{
    flags |= SDL_WINDOW_OPENGL;
    return *this;
}
WindowBuilder &WindowBuilder::vulkan()
{
    flags |= SDL_WINDOW_VULKAN;
    return *this;
}
WindowBuilder &WindowBuilder::hidden()
{
    flags |= SDL_WINDOW_HIDDEN;
    return *this;
}
WindowBuilder &WindowBuilder::borderless()
{
    flags |= SDL_WINDOW_BORDERLESS;
    return *this;
}
WindowBuilder &WindowBuilder::resizable()
{
    flags |= SDL_WINDOW_RESIZABLE;
    return *this;
}
WindowBuilder &WindowBuilder::minimized()
{
    flags |= SDL_WINDOW_MINIMIZED;
    return *this;
}
WindowBuilder &WindowBuilder::maximized()
{
    flags |= SDL_WINDOW_MAXIMIZED;
    return *this;
}
WindowBuilder &WindowBuilder::inputGrabbed()
{
    flags |= SDL_WINDOW_INPUT_GRABBED;
    return *this;
}
WindowBuilder &WindowBuilder::allowHighDpi()
{
    flags |= SDL_WINDOW_ALLOW_HIGHDPI;
    return *this;
}

WindowBuilder &WindowBuilder::positionCentered()
{
    x = SDL_WINDOWPOS_CENTERED;
    y = SDL_WINDOWPOS_CENTERED;
    return *this;
}

} // namespace sdl::video