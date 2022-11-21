/**
 * @file sample_format.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the SampleFormat constants
 * @date 2020-06-30
 */

#ifndef SDL_AUDIO_SAMPLE_FORMAT_HH
#define SDL_AUDIO_SAMPLE_FORMAT_HH

#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_mixer.h>
#include <ostream>

namespace sdl::audio
{
/**
 * @brief The format of a single audio sample. Taken from SDL_audio.h and SDL_mixer.h.
 * It's basically a wrapper around a Uint16 that can only do bitwise operations (the constants are bitflags!).
 *
 */
class SampleFormat
{
  public:
    /**
     * @brief Construct a new SampleFormat object with the given value.
     *
     * @param value the value
     */
    explicit SampleFormat(Uint16 value);

    // overloaded operators

    /**
     * @brief Perform a bitwise OR with the other format, and store it in this format.
     *
     * @param other the other format
     * @return SampleFormat& this format, after the OR is completed
     */
    SampleFormat &operator|=(const SampleFormat &other);
    /**
     * @brief Perform a bitwise AND with the other format, and store it in this format.
     *
     * @param other the other format
     * @return SampleFormat& this format, after the AND is completed
     */
    SampleFormat &operator&=(const SampleFormat &other);
    /**
     * @brief Perform a bitwise XOR with the other format, and store it in this format.
     *
     * @param other the other format
     * @return SampleFormat& this format, after the XOR is completed
     */
    SampleFormat &operator^=(const SampleFormat &other);
    /**
     * @brief Perform unary bitwise negation on this format.
     *
     * @return SampleFormat the bitwise NOT of this format
     */
    SampleFormat operator~();

    Uint16 get() const;

    // friend overloaded operators (symmetric)

    friend SampleFormat operator|(const SampleFormat &a, const SampleFormat &b);
    friend SampleFormat operator&(const SampleFormat &a, const SampleFormat &b);
    friend SampleFormat operator^(const SampleFormat &a, const SampleFormat &b);
    friend bool operator==(const SampleFormat &a, const SampleFormat &b);
    friend bool operator==(const SampleFormat &format, Uint16 value);

    /**
     * @brief Unsigned 8-bit samples
     *
     */
    static constexpr Uint16 Unsigned8Bit = AUDIO_U8;
    /**
     * @brief Signed 8-bit samples
     *
     */
    static constexpr Uint16 Signed8Bit = AUDIO_S8;
    /**
     * @brief Unsigned 16-bit samples, in little-endian byte order
     *
     */
    static constexpr Uint16 Unsigned16BitLSB = AUDIO_U16LSB;
    /**
     * @brief Signed 16-bit samples, in little-endian byte order
     *
     */
    static constexpr Uint16 Signed16BitLSB = AUDIO_S16LSB;
    /**
     * @brief Unsigned 16-bit samples, in big-endian byte order
     *
     */
    static constexpr Uint16 Unsigned16BitMSB = AUDIO_U16MSB;
    /**
     * @brief Signed 16-bit samples, in big-endian byte order
     *
     */
    static constexpr Uint16 Signed16BitMSB = AUDIO_S16MSB;
    /**
     * @brief Unsigned 16-bit samples, in the system byte order
     *
     */
    static constexpr Uint16 Unsigned16BitSystemBO = AUDIO_U16SYS;
    /**
     * @brief Signed 16-bit samples, in the system byte order
     *
     */
    static constexpr Uint16 Signed16BitSystemBO = AUDIO_S16SYS;
    /**
     * @brief The default sample format
     *
     */
    static constexpr Uint16 Default = MIX_DEFAULT_FORMAT;

  private:
    Uint16 value;
};
} // namespace sdl::audio

/**
 * @brief Perform a bitwise OR between a and b.
 * 
 * @param a the first format
 * @param b the second format
 * @return sdl::audio::SampleFormat the bitwise OR of these formats
 */
sdl::audio::SampleFormat operator|(const sdl::audio::SampleFormat &a, const sdl::audio::SampleFormat &b);
/**
 * @brief Perform a bitwise AND between a and b.
 * 
 * @param a the first format
 * @param b the second format
 * @return sdl::audio::SampleFormat the bitwise AND of these formats
 */
sdl::audio::SampleFormat operator&(const sdl::audio::SampleFormat &a, const sdl::audio::SampleFormat &b);
/**
 * @brief Perform a bitwise XOR between a and b.
 * 
 * @param a the first format
 * @param b the second format
 * @return sdl::audio::SampleFormat the bitwise XOR of these formats
 */
sdl::audio::SampleFormat operator^(const sdl::audio::SampleFormat &a, const sdl::audio::SampleFormat &b);
/**
 * @brief Check that two formats are the same.
 * 
 * @param a the first format
 * @param b the second format
 * @return true the formats are the same
 * @return false the formats are not the same
 */
bool operator==(const sdl::audio::SampleFormat &a, const sdl::audio::SampleFormat &b);
/**
 * @brief Check that two formats are the same.
 * 
 * @param format the first format
 * @param value the second format as a Uint16
 * @return true the formats are the same
 * @return false the formats are not the same
 */
bool operator==(const sdl::audio::SampleFormat &format, Uint16 value);
/**
 * @brief Check that two formats are the same.
 * 
 * @param value the first format as a Uint16
 * @param format the second format
 * @return true the formats are the same
 * @return false the formats are not the same
 */
bool operator==(Uint16 value, const sdl::audio::SampleFormat &format);

/**
 * @brief Push a string representation of `format` onto `os`.
 * 
 * @param os the stream to push to
 * @param format the format to push
 * @return std::ostream& `os` after it has been mutated
 */
std::ostream &operator<<(std::ostream &os, const sdl::audio::SampleFormat &format);

#endif // SDL_AUDIO_SAMPLE_FORMAT_HH
