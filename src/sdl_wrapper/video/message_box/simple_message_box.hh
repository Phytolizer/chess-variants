/**
 * @file simple_message_box.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the SimpleMessageBox class
 * @date 2020-06-23
 */

#ifndef SDL_WRAPPER_VIDEO_MESSAGE_BOX_SIMPLE_MESSAGE_BOX_HH
#define SDL_WRAPPER_VIDEO_MESSAGE_BOX_SIMPLE_MESSAGE_BOX_HH

#include <SDL2/SDL_stdinc.h>
#include <optional>
#include <sdl_wrapper/video/weak_window.hh>
#include <string_view>

namespace sdl::video::message_box
{
  /**
   * @brief A builder class used to set up parameters for SDL_ShowSimpleMessageBox.
   * 
   */
class SimpleMessageBox
{
  public:
    /**
     * @brief Construct a new simple message box with no configured data. Use this if you want to
     * use the builder functions.
     * 
     */
    SimpleMessageBox();
    /**
     * @brief Construct a new simple message box with existing data. Use this if you do not need
     * to use the builder functions.
     * 
     * @param kind the box kind
     * @param title the box's title
     * @param message the box's message
     * @param parent the parent window, or std::nullopt
     */
    SimpleMessageBox(Uint32 kind, std::string_view title, std::string_view message, std::optional<WeakWindow> parent);

    /**
     * @brief Finish building the message box and push it to the user.
     * 
     */
    void show();
    /**
     * @brief Set the kind of message box this is.
     * 
     * @param kind the kind
     * @return SimpleMessageBox& the box
     */
    SimpleMessageBox &kind(Uint32 kind);
    /**
     * @brief Set the message box's title.
     * 
     * @param title the title
     * @return SimpleMessageBox& the box
     */
    SimpleMessageBox &title(std::string_view title);
    /**
     * @brief Set the message box's message.
     * 
     * @param message the message
     * @return SimpleMessageBox& the box
     */
    SimpleMessageBox &message(std::string_view message);
    /**
     * @brief Set the message box's parent window.
     * 
     * @param parent the parent window
     * @return SimpleMessageBox& the box
     */
    SimpleMessageBox &parent(WeakWindow parent);

  private:
    /**
     * @brief The internal flags that are manipulated by the builder functions
     * 
     */
    Uint32 flags_;
    /**
     * @brief The internal title that is manipulated by the builder functions
     * 
     */
    std::string_view title_;
    /**
     * @brief The internal message that is manipulated by the builder functions
     * 
     */
    std::string_view message_;
    /**
     * @brief The internal parent window that is manipulated by the builder functions
     * 
     */
    std::optional<WeakWindow> window_;
};
} // namespace sdl::video::message_box

#endif // SDL_WRAPPER_VIDEO_MESSAGE_BOX_SIMPLE_MESSAGE_BOX_HH