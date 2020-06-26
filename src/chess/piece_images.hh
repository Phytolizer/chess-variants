/**
 * @file piece_images.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the PieceImages struct
 * @date 2020-06-26
 */

#ifndef CHESS_PIECE_IMAGES_HH
#define CHESS_PIECE_IMAGES_HH

#include <sdl_wrapper/render/texture.hh>

namespace chess
{
/**
 * @brief A collection of piece images for both colors.
 *
 */
struct PieceImages
{
    /**
     * @brief The image of the white version of the piece.
     *
     */
    sdl::render::Texture whiteImage;
    /**
     * @brief The image of the black version of the piece.
     *
     */
    sdl::render::Texture blackImage;
};
} // namespace chess

#endif // CHESS_PIECE_IMAGES_HH