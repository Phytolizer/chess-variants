#include "mixer_spec.hh"

std::ostream &operator<<(std::ostream &os, const sdl::mixer::MixerSpec &spec)
{
    os << "Spec { frequency: " << spec.frequency << ", format: " << spec.format << ", numChannels: " << spec.numChannels
       << " }";
}