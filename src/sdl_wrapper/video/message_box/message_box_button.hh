/**
 * @file message_box_button.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the MessageBoxButton class
 * @date 2020-06-23
 */

#ifndef SDL_WRAPPER_VIDEO_MESSAGE_BOX_MESSAGE_BOX_BUTTON_HH
#define SDL_WRAPPER_VIDEO_MESSAGE_BOX_MESSAGE_BOX_BUTTON_HH

#include <SDL2/SDL_messagebox.h>
#include <string_view>

namespace sdl::video::message_box
{
class MessageBoxButton
{
  public:
    MessageBoxButton();
    MessageBoxButton(SDL_MessageBoxButtonData data);

    MessageBoxButton &flags(SDL_MessageBoxButtonFlags flags);
    MessageBoxButton &buttonId(int id);
    MessageBoxButton &text(std::string_view text);

    SDL_MessageBoxButtonData getData();

  private:
    SDL_MessageBoxButtonData data;
};
} // namespace sdl::video::message_box

#endif // SDL_WRAPPER_VIDEO_MESSAGE_BOX_MESSAGE_BOX_BUTTON_HH