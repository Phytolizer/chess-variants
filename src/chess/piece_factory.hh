/**
 * @file piece_factory.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains the PieceFactory class
 * @date 2020-06-29
 */

#ifndef CHESS_PIECE_FACTORY_HH
#define CHESS_PIECE_FACTORY_HH

#include <SDL2/SDL_rect.h>
#include <chess/piece.hh>
#include <chess/piece_images.hh>
#include <memory>
#include <sdl_wrapper/primitives/point.hh>
#include <set>


namespace chess
{
/**
 * @brief Creates Pieces of a certain type. This type is defined by the constructor of the PieceFactory.
 *
 * The PieceFactory owns the images for its pieces. When render targets are reset, they should be reloaded.
 *
 */
class PieceFactory
{
  public:
    /**
     * @brief Construct a new Piece Factory object for a specified piece definition. Pieces
     * are defined by their set of valid moves and the images that represent them.
     *
     * @param validMoves The set of moves that are valid for this piece
     * @param whiteSurface an image of the white version of this piece
     * @param blackSurface an image of the black version of this piece
     */
    PieceFactory(std::set<sdl::primitives::Point> validMoves, sdl::surface::Surface whiteSurface,
                 sdl::surface::Surface blackSurface);

    /**
     * @brief Render the images to a texture for hardware-accelerated blitting. Blitting is done
     * for a Piece, not the factory, but the factory owns the textures.
     *
     * @param renderer the renderer to create textures with
     */
    void render(sdl::render::WeakRenderer renderer);

    /**
     * @brief Create a Piece with the specified color.
     *
     * @param color the color
     * @return Piece the piece
     */
    Piece getPiece(SDL_Color color);

  private:
    /**
     * @brief An owned image of the white version of this piece class.
     *
     */
    sdl::surface::Surface whiteSurface;
    /**
     * @brief An owned image of the black version of this piece class.
     *
     */
    sdl::surface::Surface blackSurface;
    /**
     * @brief The set of valid moves for this piece class.
     *
     */
    std::set<sdl::primitives::Point> validMoves;
    /**
     * @brief The Texture versions of whiteSurface and blackSurface.
     *
     */
    std::unique_ptr<PieceImages> images;
};
} // namespace chess

#endif // CHESS_PIECE_FACTORY_HH