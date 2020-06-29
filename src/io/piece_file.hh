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
 * @brief Read a piece file and create a PieceFactory representing that kind of piece.
 *
 * @param imgContext used to load images from file
 * @param fileName the piece file name
 * @return chess::PieceFactory
 */
chess::PieceFactory readPieceFile(sdl::image::Context &imgContext, std::string_view fileName);
} // namespace io

#endif // IO_PIECE_HH