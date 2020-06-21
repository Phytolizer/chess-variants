#include "window.hh"
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::video
{
Window::Window(__attribute__((unused)) video::Context &context, std::string_view title, int x, int y, int w, int h, Uint32 flags)
{
    handle = SDL_CreateWindow(title.data(), x, y, w, h, flags);
    if (handle == nullptr)
    {
        throw SDLException("creating window");
    }
}

Window::Window(SDL_Window *handle) : handle(handle)
{
}

Window::Window(Window &&other)
{
    handle = other.handle;
    other.handle = nullptr;
}

Window &Window::operator=(Window &&other)
{
    if (&other != this)
    {
        handle = other.handle;
        other.handle = nullptr;
    }
    return *this;
}
} // namespace sdl::video