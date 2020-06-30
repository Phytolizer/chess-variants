/**
 * @file context.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the wrapping class for SDL_mixer initialized state
 * @date 2020-06-30
 */

#ifndef SDL_MIXER_CONTEXT_HH
#define SDL_MIXER_CONTEXT_HH

#include <sdl_wrapper/mixer/init_flags.hh>
#include <sdl_wrapper/mixer/mixer_spec.hh>

namespace sdl::mixer
{
/**
 * @brief A representation of the valid state of the SDL_mixer system.
 *
 */
class Context
{
  public:
    /**
     * @brief Initialize SDL_mixer with the flags provided. Flags can be any of mixer::InitFlags
     * OR'ed together.
     *
     * @param flags the flags to initialize with
     * @param spec the audio format to use
     * @param chunkSize the number of bytes per sample. Values too small will cause skipping audio,
     * values too large will cause lagging audio.
     */
    Context(int flags, MixerSpec spec, int chunkSize);

    ~Context();

    Context(const Context &) = delete;
    Context &operator=(const Context &) = delete;

    /**
     * @brief move constructor
     *
     * @param other the object to move from
     */
    Context(Context &&other) noexcept;
    /**
     * @brief move assignment operator
     *
     * @param other the object to move from
     * @return Context& the object that was moved to
     */
    Context &operator=(Context &&other) noexcept;

    /**
     * @brief Get the actual audio format used by the audio device.
     *
     * @return MixerSpec the format
     */
    MixerSpec querySpec() const;

  private:
    bool active;
};
} // namespace sdl::mixer

#endif // SDL_MIXER_CONTEXT_HH