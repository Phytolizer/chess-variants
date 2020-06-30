#include "context.hh"
#include <sdl_wrapper/mixer/mix_exception.hh>
#include <sstream>
#include <util/util.hh>

namespace sdl::mixer
{
Context::Context(int flags, MixerSpec spec, int chunkSize) : active(true)
{
    Mix_ClearError();
    int code = Mix_Init(flags);
    if ((code & flags) != flags)
    {
        int missingFlags = ~(code & flags) & flags;
        std::stringstream message;
        message << "The following SDL mixer components failed to initialize:\n";
        if (static_cast<bool>(missingFlags & InitFlags::InitFlac))
        {
            message << "\tmixer::InitFlags::InitFlac\n";
        }
        if (static_cast<bool>(missingFlags & InitFlags::InitMod))
        {
            message << "\tmixer::InitFlags::InitMod\n";
        }
        if (static_cast<bool>(missingFlags & InitFlags::InitMp3))
        {
            message << "\tmixer::InitFlags::InitMp3\n";
        }
        if (static_cast<bool>(missingFlags & InitFlags::InitOgg))
        {
            message << "\tmixer::InitFlags::InitOgg\n";
        }
        if (static_cast<bool>(missingFlags & InitFlags::InitMid))
        {
            message << "\tmixer::InitFlags::InitMid\n";
        }
        if (static_cast<bool>(missingFlags & InitFlags::InitOpus))
        {
            message << "\tmixer::InitFlags::InitOpus\n";
        }
        message << "Reason";
        if (std::string(Mix_GetError()).empty())
        {
            message << " not given";
            throw std::runtime_error(message.str());
        }
        else // NOLINT: choosing exception to throw, both branches throw
        {
            // MixException adds the ": " part
            throw MixException(message.str());
        }
    }
    code = Mix_OpenAudio(spec.frequency, spec.format, spec.numChannels, chunkSize);
    if (code != 0)
    {
        throw MixException(util::concat("opening audio with spec: ", spec));
    }
}

Context::~Context()
{
    if (active)
    {
        Mix_CloseAudio();
        while (Mix_Init(0) != 0)
        {
            Mix_Quit();
        }
    }
}

Context::Context(Context &&other) noexcept : active(other.active)
{
    other.active = false;
}

Context &Context::operator=(Context &&other) noexcept
{
    if (&other != this)
    {
        active = other.active;
        other.active = false;
    }
    return *this;
}

// NOLINTNEXTLINE(readability-convert-member-functions-to-static): this relies on a valid context
MixerSpec Context::querySpec() const
{
    int frequency = 0;
    Uint16 format = 0;
    int channels = 0;
    int code = Mix_QuerySpec(&frequency, &format, &channels);
    if (code == 0)
    {
        throw MixException("querying spec");
    }
    return {frequency, format, channels};
}
} // namespace sdl::mixer