/**
 * @file main.cc
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief The main file
 * @date 2020-06-24
 */

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <sdl_wrapper/context.hh>
#include <sdl_wrapper/render/renderer.hh>
#include <sdl_wrapper/render/texture.hh>
#include <sdl_wrapper/video/window.hh>

#include "chess/chessGame.hh"
#include <cmath>
#include <iostream>
#include <vector>

using std::cerr;

/**
 * @brief Draw the chess board for the game. It is drawn to a texture which is then returned.
 *
 * @param renderer a renderer that is able to target textures
 * @param pixelFormat the pixel format to use for the texture
 * @return sdl::render::Texture a texture with a chess board on it
 */
sdl::render::Texture drawChessBoard(sdl::render::Renderer &renderer, Uint32 pixelFormat)
{
}

/**
 * @brief The main function.
 *
 * @return int The exit status code.
 * 0 for success, non-zero for failure.
 */
int main()
{
    int width = 720;
    int height = 480;
    int margin = 8; // percent out of 100
    int xGridAmount = 5;
    int yGridAmount = 10;

    sdl::Context sdlContext;
    sdl::video::Context videoContext = sdlContext.initVideo();

    sdl::video::Window window =
        videoContext.createWindow("test window", 0, 0, width, height).positionCentered().resizable().build();

    sdl::render::Renderer renderer = window.createRenderer().accelerated().build();

    chess::ChessGame activeGame(xGridAmount, yGridAmount);
    activeGame.redraw(renderer, width, height, margin, xGridAmount, yGridAmount);

    bool run = true;
    while (run)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                run = false;
                break;
            }
            if (e.type == SDL_WINDOWEVENT)
            {
                SDL_WindowEvent we = e.window;
                if (we.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    width = we.data1;
                    height = we.data2;
                    activeGame.redraw(renderer, width, height, margin, xGridAmount, yGridAmount);
                }
            }
        }

        renderer.setDrawColor({0x44, 0x44, 0x44, 0xff});
        renderer.clear();

        activeGame.displayGrid(renderer);

        renderer.present();
    }

    return 0;
}
