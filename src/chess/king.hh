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
    King(int x, int y, SDL_Color color);
    void display() override;
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
    bool validateMove(SDL_Point relMove) override;

  private:
    static const std::vector<SDL_Point> validMoves;
};
} // namespace chess

#endif // CHESS_KING_HH