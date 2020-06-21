/**
 * @file sdl_video_context.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a wrapper for the SDL video subsystem
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_SDL_VIDEO_CONTEXT_HH
#define SDL_WRAPPER_SDL_VIDEO_CONTEXT_HH

namespace sdl
{
// predeclaration, prevent recursive includes
class Context;
} // namespace sdl

namespace sdl::video
{

class Context
{
  public:
    Context(__attribute__((unused))::sdl::Context &parent);

    ~Context();

    /// no copy constructor
    Context(const Context &) = delete;
    /// no copy assignment
    Context &operator=(const Context &) = delete;
    Context(Context &&);
    Context &operator=(Context &&);

  private:
    bool active;
};
} // namespace sdl::video

#endif // SDL_WRAPPER_SDL_VIDEO_CONTEXT_HH