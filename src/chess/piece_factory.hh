/**
 * @file piece_factory.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a factory for Piece objects.
 * @date 2020-06-26
 */

#ifndef CHESS_PIECE_FACTORY_HH
#define CHESS_PIECE_FACTORY_HH

#include <chess/piece_images.hh>
#include <SDL2/SDL_rect.h>
#include <chess/piece.hh>
#include <sdl_wrapper/render/texture.hh>
#include <vector>

namespace chess
{

/**
 * @brief Creates many Piece objects of a particular type (e.g. King, Knight, etc.)
 *
 */
class PieceFactory
{
  public:
    /**
     * @brief Construct a new piece factory for a piece with specified valid moves and images.
     */
    PieceFactory();
    /**
     * @brief Create the specified chess piece.
     *
     * @param validMoves the piece's valid moves
     * @param images the images of the piece to render
     * @return Piece a piece with the requested format
     */
    Piece create(std::vector<SDL_Point> validMoves, PieceImages images);

  private:
};
} // namespace chess

#endif // CHESS_PIECE_FACTORY_HH