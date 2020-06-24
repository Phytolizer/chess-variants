/**
 * @file king.hh
 * @author Kyle Coffefy (kylecoffey1999@gmail.com)
 * @brief Defines the standard chess king
 * @date 2020-06-22
 */

#ifndef CHESS_KING_HH
#define CHESS_KING_HH

#include <SDL2/SDL_video.h>
#include <chess/piece.hh>
#include <vector>

namespace chess
{
/**
 * @brief A King piece in chess. The king can move and capture any adjacent or diagonally adjacent tile.
 *
 */
class King : public Piece
{
  public:
    /**
     * @brief Construct a new King at a specific position and color.
     * 
     * @param x the x-coordinate on the board
     * @param y the y-coordinate on the board
     * @param color the color of the king
     */
    King(int x, int y, SDL_Color color);
    /**
     * @brief Display the King as an image.
     *
     * @todo pass renderer here?
     * @todo implement
     * 
     */
    void display() override;
    /**
     * @brief Display the King as a transparent image.
     * 
     */
    void displayTransparent() override;
    /**
     * @brief Get the valid moves for the king.
     * They look like:
     *
     * ```
     * .....
     * .xxx.
     * .x*x.
     * .xxx.
     * .....
     * ```
     *
     * @return std::vector<SDL_Point> the moves as a vector of offsets from the king's current position
     */
    std::vector<SDL_Point> getValidMoves() override;
    /**
     * @brief Check that a given move is valid for the King.
     * 
     * @param relMove the move relative to the king's current position
     * @return true the move is valid
     * @return false the move is not valid
     */
    bool validateMove(SDL_Point relMove) override;

  private:
    static const std::vector<SDL_Point> validMoves;
};
} // namespace chess

#endif // CHESS_KING_HH