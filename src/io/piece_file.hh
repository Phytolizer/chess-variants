/**
 * @file piece_file.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains functions involving reading of .piece files
 * @date 2020-06-26
 */

#ifndef IO_PIECE_HH
#define IO_PIECE_HH

#include <chess/piece.hh>
#include <chess/piece_factory.hh>
#include <chess/piece_images.hh>
#include <sdl_wrapper/image/context.hh>
#include <sdl_wrapper/render/renderer.hh>
#include <string_view>

/**
 * @namespace io
 * @brief Contains functions and classes related to file I/O for special file formats.
 *
 */
namespace io
{
/**
 * @brief Read a piece file and create a Piece representing it.
 *
 * @param imgContext the SDL_image context used to load image files
 * @param renderer the renderer to create the image textures with
 * @param factory the piece factory for creating the piece
 * @param fileName the file to load
 * @return chess::Piece the piece prototype
 */
chess::Piece readPieceFile(sdl::image::Context &imgContext, sdl::render::Renderer &renderer,
                           chess::PieceFactory &factory, std::string_view fileName);
} // namespace io

#endif // IO_PIECE_HH