/**
 * @file surface.hh
 * @author your name (you@domain.com)
 * @brief Contains a wrapper for SDL_Surface
 * @date 2020-06-22
 */

#ifndef SDL_WRAPPER_SURFACE_SURFACE_HH
#define SDL_WRAPPER_SURFACE_SURFACE_HH

#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <sdl_wrapper/surface/weak_surface.hh>

/**
 * @namespace sdl::surface
 * @brief Contains most functions and classes based on SDL_surface.h
 *
 */
namespace sdl::surface
{
/**
 * @brief A structured collection of pixels used in software rendering. Hardware rendering is not
 * done with surfaces.
 *
 * @see sdl::render::Renderer
 *
 */
class Surface : public WeakSurface
{
  public:
    /**
     * @brief Construct a new Surface from an existing SDL handle.
     * 
     * @param handle the handle
     */
    Surface(SDL_Surface *handle);
    /**
     * @brief Construct a new Surface with a specific width, height, bit depth, and color mask.
     *
     * @param width the surface's width in pixels
     * @param height the surface's height in pixels
     * @param depth the number of bits per pixel
     * @param rmask the red component of a color mask
     * @param gmask the green component of a color mask
     * @param bmask the blue component of a color mask
     * @param amask the alpha component of a color mask
     */
    Surface(int width, int height, int depth, Uint32 rmask, Uint32 gmask, Uint32 bmask, Uint32 amask);
    /**
     * @brief Construct a new Surface with a specific width, height, depth, and pixel format.
     *
     * @param width the surface's width in pixels
     * @param height the surface's height in pixels
     * @param depth the number of bits per pixel
     * @param pixelFormat the pixel format, e.g. SDL_PIXELFORMAT_RGBA8888 for a 32-bit
     * RGBA color with 8 bits per component
     */
    Surface(int width, int height, int depth, Uint32 pixelFormat);

    ~Surface();

    Surface(const Surface &) = delete;
    Surface &operator=(const Surface &) = delete;

    /**
     * @brief move constructor
     *
     * @param other the object to move from
     */
    Surface(Surface &&other);
    /**
     * @brief move assignment operator
     *
     * @param other the object to move from
     * @return Surface& the object that was moved to
     */
    Surface &operator=(Surface &&other);
};

// free functions

/**
 * @brief Convert pixels from one format to another.
 *
 * @param width the width in pixels of the block
 * @param height the height in pixels of the block
 * @param srcFormat the pixel format of the source
 * @param srcPitch the pitch (bit depth) of the source
 * @param src the source pixels
 * @param dstFormat the pixel format of the destination
 * @param dstPitch the pitch (bit depth) of the destination
 * @param dst the destination
 */
void convertPixels(int width, int height, Uint32 srcFormat, int srcPitch, const void *src, Uint32 dstFormat,
                   int dstPitch, void *dst);

} // namespace sdl::surface

#endif // SDL_WRAPPER_SURFACE_SURFACE_HH