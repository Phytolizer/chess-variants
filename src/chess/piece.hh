/**
 * @file piece.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains an abstract class through which chess pieces can be defined
 * @date 2020-06-22
 */

#ifndef CHESS_PIECE_HH
#define CHESS_PIECE_HH

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_video.h>
#include <chess/piece_images.hh>
#include <set>

namespace chess
{
/**
 * @brief An abstract chess piece. Pieces have a way to display themselves, a crown (if they are the
 * piece that needs to be checkmated), a selected state, a set of valid moves, and a color (typically
 * white or black).
 *
 */
class Piece
{
  public:
    /**
     * @brief Render the piece to the screen.
     *
     */
    void display();
    /**
     * @brief Give this piece a crown. Only one piece should have a crown.
     * The piece with the crown will lose the game if it is checkmated.
     *
     */
    void giveCrown();
    /**
     * @brief Take the crown from this piece in order to give it to another.
     *
     */
    void takeCrown();
    /**
     * @brief Check if this piece has a crown.
     *
     * @return true the piece has a crown
     * @return false the piece does not have a crown
     */
    bool hasCrown();
    /**
     * @brief Get the valid moves for this piece. Valid moves are relative to the
     * piece's current position. Positive y values represent the forward direction.
     * For white, this is up (-y). For black, it is down (+y).
     * Negative x values represent the left direction. For white, this is left (-x). For black,
     * it is right (+x).
     *
     * @return std::vector<SDL_Point>
     */
    std::vector<SDL_Point> getValidMoves();
    /**
     * @brief Check that a specific move is valid for the piece.
     *
     * @param relMove the move relative to the piece's current position
     * @return true the move is valid
     * @return false the move is not valid
     */
    bool validateMove(SDL_Point relMove);

  protected:
    /**
     * @brief The piece's color, typically white or black
     *
     */
    SDL_Color color;
    /**
     * @brief Whether the piece has a crown. The piece with the crown is the piece that needs to be
     * checkmated to win the game.
     *
     */
    bool hasCrown_;
    /**
     * @brief The moves that are valid for this piece. Moves are SDL_Points centered around the piece's current
     * position.
     *
     */
    const std::set<SDL_Point> &validMoves;
    /**
     * @brief The images of this piece, for blitting to the screen. They are owned by its factory.
     *
     */
    const PieceImages &images;
    /**
     * @brief The factory that created this piece. Useful in play for re-rendering a piece.
     *
     */
    PieceFactory &factory;
};
} // namespace chess

#endif // CHESS_PIECE_HH
