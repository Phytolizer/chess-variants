/**
 * @file mixer_spec.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the AudioSpec struct
 * @date 2020-06-30
 */

#ifndef SDL_MIXER_MIXER_SPEC_HH
#define SDL_MIXER_MIXER_SPEC_HH

#include <SDL2/SDL_stdinc.h>
#include <ostream>
#include <sdl_wrapper/audio/sample_format.hh>

namespace sdl::mixer
{
/**
 * @brief The audio format used by an audio device
 */
struct MixerSpec
{
    /**
     * @brief The sample frequency used by the device
     *
     */
    int frequency;
    /**
     * @brief The output format used by the device, a value from audio::SampleFormat
     *
     */
    audio::SampleFormat format;
    /**
     * @brief the number of channels opened, usually 1 or 2 (mono/stereo)
     *
     */
    int numChannels;
};
} // namespace sdl::mixer

/**
 * @brief Push the MixerSpec onto the ostream provided.
 * 
 * @param os the ostream
 * @param spec the spec
 * @return std::ostream& the ostream after being mutated
 */
std::ostream &operator<<(std::ostream &os, const sdl::mixer::MixerSpec &spec);
#endif // SDL_MIXER_MIXER_SPEC_HH