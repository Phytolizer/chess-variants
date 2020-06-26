#include "rwops.hh"
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::io
{
RWops::RWops() : handle(SDL_AllocRW()), allocd(true)
{
    if (handle == nullptr)
    {
        throw SDLException("allocating RWops object");
    }
}
RWops::RWops(const void *constMem, int size) : handle(SDL_RWFromConstMem(constMem, size)), allocd(false)
{
    if (handle == nullptr)
    {
        throw SDLException("creating RWops from const memory");
    }
}
RWops::RWops(std::string_view fileName, std::string_view mode)
    : handle(SDL_RWFromFile(fileName.data(), mode.data())), allocd(false)
{
    if (handle == nullptr)
    {
        throw SDLException("creating RWops from file");
    }
}
RWops::RWops(FILE *fp, bool autoClose) : handle(SDL_RWFromFP(fp, autoClose ? SDL_TRUE : SDL_FALSE)), allocd(false)
{
    if (handle == nullptr)
    {
        throw SDLException("creating RWops from previously opened file");
    }
}
RWops::RWops(void *mem, int size) : handle(SDL_RWFromMem(mem, size)), allocd(false)
{
    if (handle == nullptr)
    {
        throw SDLException("creating RWops from raw memory");
    }
}

RWops::~RWops()
{
    if (handle != nullptr)
    {
        if (allocd)
        {
            SDL_FreeRW(handle);
        }
        else
        {
            SDL_RWclose(handle);
        }
    }
}

RWops::RWops(RWops &&other) : handle(other.handle), allocd(other.allocd)
{
    other.handle = nullptr;
}

RWops &RWops::operator=(RWops &&other)
{
    if (&other != this)
    {
        handle = other.handle;
        allocd = other.allocd;
        other.handle = nullptr;
    }
    return *this;
}

std::vector<std::byte> RWops::read(Uint32 amt)
{
    std::vector<std::byte> bytes(amt);
    int amtRead = SDL_RWread(handle, bytes.data(), 1, amt);
    if (amtRead == 0)
    {
        throw SDLException("reading fixed number of bytes from stream");
    }
    return bytes;
}
} // namespace sdl::io