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
class SimpleMessageBox
{
  public:
    SimpleMessageBox();
    SimpleMessageBox(Uint32 kind, std::string_view title, std::string_view message, std::optional<WeakWindow> parent);

    void show();
    SimpleMessageBox &kind(Uint32 kind);
    SimpleMessageBox &title(std::string_view title);
    SimpleMessageBox &message(std::string_view message);
    SimpleMessageBox &parent(WeakWindow parent);

  private:
    Uint32 flags_;
    std::string_view title_;
    std::string_view message_;
    std::optional<WeakWindow> window_;
};
} // namespace sdl::video::message_box

#endif // SDL_WRAPPER_VIDEO_MESSAGE_BOX_SIMPLE_MESSAGE_BOX_HH