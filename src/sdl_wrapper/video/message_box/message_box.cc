#include "message_box.hh"
#include <sdl_wrapper/sdl_exception.hh>

namespace sdl::video::message_box
{
MessageBox::MessageBox() : data({})
{
}

MessageBox::MessageBox(SDL_MessageBoxData data) : data(data)
{
}

int MessageBox::show()
{
    int buttonid;
    int code = SDL_ShowMessageBox(&data, &buttonid);
    if (code != 0)
    {
        throw SDLException("showing message box");
    }
    return buttonid;
}

MessageBox &MessageBox::setKind(SDL_MessageBoxFlags kind)
{
    data.flags = kind;
    return *this;
}

MessageBox &MessageBox::setParentWindow(video::WeakWindow parent)
{
    data.window = parent.getHandle();
    return *this;
}

MessageBox &MessageBox::setTitle(std::string_view title)
{
    data.title = title.data();
    return *this;
}

MessageBox &MessageBox::setMessage(std::string_view message)
{
    data.message = message.data();
    return *this;
}

MessageBox &MessageBox::setButtons(std::vector<MessageBoxButton> buttons)
{
    data.numbuttons = buttons.size();
    SDL_MessageBoxButtonData *bs = new SDL_MessageBoxButtonData[data.numbuttons];
    for (int i = 0; i < data.numbuttons; i++)
    {
        bs[i] = buttons[i].getData();
    }
    data.buttons = bs;
    return *this;
}

MessageBox &MessageBox::setColorScheme(const SDL_MessageBoxColorScheme &cs)
{
    data.colorScheme = &cs;
    return *this;
}
} // namespace sdl::video::message_box