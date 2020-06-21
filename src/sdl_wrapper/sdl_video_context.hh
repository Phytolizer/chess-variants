/**
 * @file sdl_video_context.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a wrapper for the SDL video subsystem
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_SDL_VIDEO_CONTEXT_HH
#define SDL_WRAPPER_SDL_VIDEO_CONTEXT_HH

// predeclaration, prevent recursive includes
class SDLContext;

class SDLVideoContext
{
  public:
    SDLVideoContext(SDLContext &parent);

    ~SDLVideoContext();

    /// no copy constructor
    SDLVideoContext(const SDLVideoContext &) = delete;
    /// no copy assignment
    SDLVideoContext &operator=(const SDLVideoContext &) = delete;
    SDLVideoContext(SDLVideoContext &&);
    SDLVideoContext &operator=(SDLVideoContext &&);

    private:
    bool active;
};

#endif // SDL_WRAPPER_SDL_VIDEO_CONTEXT_HH