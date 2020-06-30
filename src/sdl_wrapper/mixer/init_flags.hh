/**
 * @file init_flags.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the InitFlags constants
 * @date 2020-06-30
 */

#ifndef SDL_MIXER_INIT_FLAGS_HH
#define SDL_MIXER_INIT_FLAGS_HH

#include <SDL2/SDL_mixer.h>

namespace sdl::mixer
{
/**
 * @brief These constants are passed to the mixer::Context constructor.
 * They determine which sample/music formats to support.
 *
 * Internally, they are passed to Mix_Init.
 *
 */
class InitFlags
{
  public:
    /**
     * @brief Support the FLAC encoding.
     * 
     */
    static constexpr int InitFlac = MIX_INIT_FLAC;
    /**
     * @brief Support the MOD encoding.
     * 
     */
    static constexpr int InitMod = MIX_INIT_MOD;
    /**
     * @brief Support the MP3 encoding.
     * 
     */
    static constexpr int InitMp3 = MIX_INIT_MP3;
    /**
     * @brief Support the Ogg Vorbis encoding.
     * 
     */
    static constexpr int InitOgg = MIX_INIT_OGG;
    /**
     * @brief Support the MID encoding.
     * 
     */
    static constexpr int InitMid = MIX_INIT_MID;
    /**
     * @brief Support the OPUS encoding.
     * 
     */
    static constexpr int InitOpus = MIX_INIT_OPUS;
};
} // namespace sdl::mixer

#endif // SDL_MIXER_INIT_FLAGS_HH