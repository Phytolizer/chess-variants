/**
 * @file message_box.hh
 * @author your name (you@domain.com)
 * @brief Contains the sdl::video::MessageBox class
 * @date 2020-06-23
 */

#ifndef SDL_WRAPPER_VIDEO_MESSAGE_BOX_HH
#define SDL_WRAPPER_VIDEO_MESSAGE_BOX_HH

#include <SDL2/SDL_messagebox.h>
#include <sdl_wrapper/video/message_box/message_box_button.hh>
#include <sdl_wrapper/video/weak_window.hh>


namespace sdl::video::message_box
{
/**
 * @brief A builder class to show a less simple message box to the user, a temporary popup
 * window with a message and options for response.
 *
 */
class MessageBox
{
  public:
    /**
     * @brief Construct a new message box with no parameters. Use the builder functions to set them.
     *
     */
    MessageBox();
    MessageBox(SDL_MessageBoxData data);
    int show();
    MessageBox &setKind(SDL_MessageBoxFlags kind);
    MessageBox &setParentWindow(video::WeakWindow parent);
    MessageBox &setTitle(std::string_view title);
    MessageBox &setMessage(std::string_view message);
    MessageBox &setButtons(std::vector<MessageBoxButton> buttons);
    MessageBox &setColorScheme(const SDL_MessageBoxColorScheme &cs);

  private:
    SDL_MessageBoxData data;
};
} // namespace sdl::video::message_box

#endif // SDL_WRAPPER_VIDEO_MESSAGE_BOX_HH