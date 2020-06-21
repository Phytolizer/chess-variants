/**
 * @file sdl_context.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a wrapper for initializing and deinitializing
 * SDL and its systems.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_SDL_CONTEXT_HH
#define SDL_WRAPPER_SDL_CONTEXT_HH

#include <sdl_wrapper/sdl_video_context.hh>

/**
 * @brief An RAII wrapper for SDL's initialization and
 * deinitialization.
 */
class SDLContext
{
  public:
    /**
     * @brief Construct a new SDLContext object. Constructing
     * this object results in a call to SDL_Init(0).
     * 
     */
    SDLContext();
    ~SDLContext();

    /// no copy constructors
    SDLContext(const SDLContext &) = delete;
    /// no copy assignment
    SDLContext &operator=(const SDLContext &) = delete;

    SDLContext(SDLContext &&);
    SDLContext &operator=(SDLContext &&);

    SDLVideoContext initVideo();

  private:
    bool active;
};

#endif // SDL_WRAPPER_SDL_CONTEXT_HH