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
/**
 * @brief A builder for the SDL_MessageBoxButton struct. Has flags, a user-defined ID, and some text.
 *
 */
class MessageBoxButton
{
  public:
    /**
     * @brief Construct a new message box button with no data specified.
     * Use this constructor if you want to use the builder functions.
     * 
     */
    MessageBoxButton();
    /**
     * @brief Construct a new message box button from existing data.
     * 
     * @param data the data
     */
    MessageBoxButton(SDL_MessageBoxButtonData data);

    /**
     * @brief Set the button's flags.
     * 
     * @param flags the flags
     * @return MessageBoxButton& the button
     */
    MessageBoxButton &flags(SDL_MessageBoxButtonFlags flags);
    /**
     * @brief Set the button's ID. This ID is returned by MessageBox::show().
     * 
     * @param id the ID
     * @return MessageBoxButton& the button
     */
    MessageBoxButton &buttonId(int id);
    /**
     * @brief Set the text that is on the button.
     * 
     * @param text the text
     * @return MessageBoxButton& the button
     */
    MessageBoxButton &text(std::string_view text);

    /**
     * @brief Get the internal data of this button. Use this when you are finished configuring it.
     * 
     * @return SDL_MessageBoxButtonData the data
     */
    SDL_MessageBoxButtonData getData();

  private:
    /**
     * @brief Internal data that is manipulated by the builder functions.
     * 
     */
    SDL_MessageBoxButtonData data;
};
} // namespace sdl::video::message_box

#endif // SDL_WRAPPER_VIDEO_MESSAGE_BOX_MESSAGE_BOX_BUTTON_HH