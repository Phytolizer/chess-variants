#include "window.hh"
#include "SDL2/SDL_video.h"
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::video
{
Window::Window(video::Context &, std::string_view title, int x, int y, int w, int h, Uint32 flags)
    : WeakWindow(SDL_CreateWindow(title.data(), x, y, w, h, flags))
{
    if (handle == nullptr)
    {
        throw SDLException("creating window");
    }
}

Window::Window(const void *nativeData) : WeakWindow(SDL_CreateWindowFrom(nativeData))
{
    if (handle == nullptr)
    {
        throw SDLException("creating window from native window");
    }
}

Window::~Window()
{
    if (handle != nullptr)
    {
        SDL_DestroyWindow(handle);
    }
}

Window::Window(Window &&other) : WeakWindow(other.handle)
{
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