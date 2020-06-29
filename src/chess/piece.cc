#include "piece.hh"
#include <stdexcept>

namespace chess
{
Piece::Piece(PieceFactory &factory, const std::set<SDL_Point> &validMoves, const PieceImages &images,
             SDL_Color color)
    : color(color), hasCrown_(false), validMoves(validMoves), images(images), factory(factory)
{
}
void Piece::giveCrown()
{
    if (!hasCrown_)
    {
        hasCrown_ = true;
    }
    else
    {
        throw std::runtime_error("giving crown to piece with crown");
    }
}
void Piece::takeCrown()
{
    if (hasCrown_)
    {
        hasCrown_ = false;
    }
    else
    {
        throw std::runtime_error("taking crown from piece without crown");
    }
}
bool Piece::hasCrown()
{
    return hasCrown_;
}
} // namespace chess
