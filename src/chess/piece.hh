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
#include <vector>


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
    virtual void display() = 0;
    virtual void displayTransparent() = 0;
    void toggleSelected();
    void giveCrown();
    void takeCrown();
    bool hasCrown();
    virtual std::vector<SDL_Point> getValidMoves() = 0;
    virtual bool validateMove(SDL_Point relMove) = 0;

  protected:
    SDL_Color color;
    int x;
    int y;
    bool selected;
    bool hasCrown_;
};
} // namespace chess

#endif // CHESS_PIECE_HH