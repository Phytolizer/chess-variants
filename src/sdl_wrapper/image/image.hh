/**
 * @file image.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief The root for all of SDL_image.
 * @date 2020-06-25
 */

#ifndef SDL_WRAPPER_IMAGE_IMAGE_HH
#define SDL_WRAPPER_IMAGE_IMAGE_HH

#include <SDL2/SDL_image.h>
#include <sdl_wrapper/surface/surface.hh>
#include <string_view>

/**
 * @namespace sdl::image
 * @brief The image namespace contains all SDL_image structures and functions.
 *
 */
namespace sdl::image
{
/**
 * @brief A friendly wrapper for IMG_INIT_* flags.
 *
 */
enum class InitFlags : int
{
    Jpg = IMG_INIT_JPG,
    Png = IMG_INIT_PNG,
    Tiff = IMG_INIT_TIF
};
} // namespace sdl::image

#endif // SDL_WRAPPER_IMAGE_IMAGE_HH