/**
 * @file colors.hh
 * @author your name (you@domain.com)
 * @brief Defines common colors.
 * @date 2020-06-22
 */

#ifndef SDL_WRAPPER_COLORS_HH
#define SDL_WRAPPER_COLORS_HH

#include <SDL2/SDL_video.h>

namespace sdl::colors
{
constexpr SDL_Color Black{0x00, 0x00, 0x00, 0xff};
constexpr SDL_Color White{0xff, 0xff, 0xff, 0xff};
constexpr SDL_Color Red{0xff, 0x00, 0x00, 0xff};
constexpr SDL_Color Orange{0xff, 0xa5, 0x00, 0xff};
constexpr SDL_Color Yellow{0xff, 0xff, 0x00, 0xff};
constexpr SDL_Color Green{0x00, 0xff, 0x00, 0xff};
constexpr SDL_Color Blue{0x00, 0x00, 0xff, 0xff};
constexpr SDL_Color Magenta{0xff, 0x00, 0xff, 0xff};

constexpr SDL_Color Transparent{0x00, 0x00, 0x00, 0x00};
} // namespace sdl::colors

#endif // SDL_WRAPPER_COLORS_HH