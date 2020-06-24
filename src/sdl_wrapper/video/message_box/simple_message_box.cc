#include "simple_message_box.hh"
#include <SDL2/SDL_messagebox.h>
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::video::message_box
{
SimpleMessageBox::SimpleMessageBox() : flags_(0), title_(""), message_(""), window_(std::nullopt)
{
}

SimpleMessageBox::SimpleMessageBox(Uint32 kind, std::string_view title, std::string_view message,
                                   std::optional<WeakWindow> parent)
    : flags_(kind), title_(title), message_(message), window_(parent)
{
}

void SimpleMessageBox::show()
{
    SDL_Window *windowP = nullptr;
    if (window_)
    {
        windowP = window_->getHandle();
    }
    int code = SDL_ShowSimpleMessageBox(flags_, title_.data(), message_.data(), windowP);
    if (code != 0)
    {
        throw SDLException("showing simple message box");
    }
}

SimpleMessageBox &SimpleMessageBox::kind(Uint32 kind)
{
    flags_ = kind;
    return *this;
}

SimpleMessageBox &SimpleMessageBox::title(std::string_view title)
{
    title_ = title;
    return *this;
}

SimpleMessageBox &SimpleMessageBox::message(std::string_view message)
{
    message_ = message;
    return *this;
}

SimpleMessageBox &SimpleMessageBox::parent(WeakWindow parent)
{
    window_ = {parent};
    return *this;
}
} // namespace sdl::video::message_box