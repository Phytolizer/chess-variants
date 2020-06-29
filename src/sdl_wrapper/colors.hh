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
/**
 * @brief Opaque black (000000)
 *
 */
constexpr SDL_Color Black{0x00, 0x00, 0x00, 0xff};
/**
 * @brief Opaque white (FFFFFF)
 *
 */
constexpr SDL_Color White{0xff, 0xff, 0xff, 0xff};
/**
 * @brief Opaque red (FF0000)
 *
 */
constexpr SDL_Color Red{0xff, 0x00, 0x00, 0xff};
/**
 * @brief Opaque orange (FFA500)
 *
 */
constexpr SDL_Color Orange{0xff, 0xa5, 0x00, 0xff};
/**
 * @brief Opaque yellow (FFFF00)
 *
 */
constexpr SDL_Color Yellow{0xff, 0xff, 0x00, 0xff};
/**
 * @brief Opaque green (00FF00)
 *
 */
constexpr SDL_Color Green{0x00, 0xff, 0x00, 0xff};
/**
 * @brief Opaque blue (0000FF)
 *
 */
constexpr SDL_Color Blue{0x00, 0x00, 0xff, 0xff};
/**
 * @brief Opaque magenta (FF00FF)
 *
 */
constexpr SDL_Color Magenta{0xff, 0x00, 0xff, 0xff};

/**
 * @brief Complete transparency (alpha of 0x00)
 *
 */
constexpr SDL_Color Transparent{0x00, 0x00, 0x00, 0x00};
} // namespace sdl::colors

#endif // SDL_WRAPPER_COLORS_HH