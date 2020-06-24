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

/**
 * @namespace sdl::video::message_box
 * @brief Contains several classes for two primary functions inside SDL_video.h,
 * namely SDL_ShowMessageBox and SDL_ShowSimpleMessageBox.
 *
 */
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
    /**
     * @brief Construct a new message box with the data specified. Do not call the builder functions
     * in this case (unless you just want to).
     *
     * @param data the message box specification
     */
    MessageBox(SDL_MessageBoxData data);
    /**
     * @brief Finish the message box and push it to the user.
     *
     * @return int the index of the button that was pressed
     */
    int show();
    /**
     * @brief Set the kind of message box this is.
     *
     * @param kind the kind
     * @return MessageBox& the object being worked on
     */
    MessageBox &setKind(SDL_MessageBoxFlags kind);
    /**
     * @brief Set the message box's parent window.
     *
     * @param parent the parent window
     * @return MessageBox& the object being worked on
     */
    MessageBox &setParentWindow(video::WeakWindow parent);
    /**
     * @brief Set the message box's title.
     *
     * @param title the title
     * @return MessageBox& the object being worked on
     */
    MessageBox &setTitle(std::string_view title);
    /**
     * @brief Set the message box's message.
     *
     * @param message the message
     * @return MessageBox& the object being worked on
     */
    MessageBox &setMessage(std::string_view message);
    /**
     * @brief Set the buttons that will appear on the message box.
     *
     * @param buttons the buttons
     * @return MessageBox& the object being worked on
     */
    MessageBox &setButtons(std::vector<MessageBoxButton> buttons);
    /**
     * @brief Set the message box's color scheme.
     *
     * @param cs the color scheme
     * @return MessageBox& the object being worked on
     */
    MessageBox &setColorScheme(const SDL_MessageBoxColorScheme &cs);

  private:
    /**
     * @brief The internal data used by the builder functions.
     *
     */
    SDL_MessageBoxData data;
};
} // namespace sdl::video::message_box

#endif // SDL_WRAPPER_VIDEO_MESSAGE_BOX_HH