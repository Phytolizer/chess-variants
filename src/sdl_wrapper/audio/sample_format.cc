#include "sample_format.hh"

namespace sdl::audio
{
SampleFormat::SampleFormat(Uint16 value) : value(value)
{
}
Uint16 SampleFormat::get() const
{
    return value;
}
} // namespace sdl::audio
std::ostream &operator<<(std::ostream &os, const sdl::audio::SampleFormat &format)
{
    return os << format.get();
}
