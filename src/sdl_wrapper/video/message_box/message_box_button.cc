#include "message_box_button.hh"

namespace sdl::video::message_box
{
MessageBoxButton::MessageBoxButton() : data({})
{
}

MessageBoxButton::MessageBoxButton(SDL_MessageBoxButtonData data) : data(data)
{
}

MessageBoxButton &MessageBoxButton::flags(SDL_MessageBoxButtonFlags flags)
{
    data.flags = flags;
    return *this;
}

MessageBoxButton &MessageBoxButton::buttonId(int id)
{
    data.buttonid = id;
    return *this;
}

MessageBoxButton &MessageBoxButton::text(std::string_view text)
{
    data.text = text.data();
    return *this;
}

SDL_MessageBoxButtonData MessageBoxButton::getData()
{
    return data;
}
} // namespace sdl::video::message_box