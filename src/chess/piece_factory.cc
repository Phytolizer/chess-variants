#include "piece_factory.hh"
#include <stdexcept>

namespace chess
{
PieceFactory::PieceFactory(std::set<SDL_Point> validMoves, sdl::surface::Surface whiteSurface,
                           sdl::surface::Surface blackSurface)
    : whiteSurface(std::move(whiteSurface)), blackSurface(std::move(blackSurface)), validMoves(std::move(validMoves)),
      images(nullptr)
{
}

void PieceFactory::render(sdl::render::WeakRenderer renderer)
{
    if (images == nullptr)
    {
        sdl::render::Texture whiteTexture(renderer, whiteSurface);
        sdl::render::Texture blackTexture(renderer, blackSurface);
        images = std::make_unique<PieceImages>(PieceImages{std::move(whiteTexture), std::move(blackTexture)});
    }
    else
    {
        images->whiteImage = sdl::render::Texture(renderer, whiteSurface);
        images->blackImage = sdl::render::Texture(renderer, blackSurface);
    }
}

Piece PieceFactory::getPiece(SDL_Color color)
{
    if (images == nullptr)
    {
        throw std::runtime_error(
            "Cannot create piece: images have not been rendered. Try calling PieceFactory::render()!");
    }
    return Piece(*this, validMoves, *images, color);
}
} // namespace chess