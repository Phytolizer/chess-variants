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
 * @brief The color used for the background in game
 *
 */
constexpr SDL_Color BG_COLOR = {0x44, 0x44, 0x44, 0xff};

/**
 * @brief The width of the initial window
 *
 */
constexpr int INITIAL_WIDTH = 720;
/**
 * @brief The height of the initial window
 *
 */
constexpr int INITIAL_HEIGHT = 480;

/**
 * @brief The main function.
 *
 * @return int The exit status code.
 * 0 for success, non-zero for failure.
 */
int main()
{
    int width = INITIAL_WIDTH;
    int height = INITIAL_HEIGHT;
    constexpr int MARGIN = 8; // percent out of 100
    constexpr int GRID_NCOLS = 5;
    constexpr int GRID_NROWS = 10;

    sdl::Context sdlContext;
    sdl::video::Context videoContext = sdlContext.initVideo();

    sdl::video::Window window =
        videoContext.createWindow("test window", 0, 0, width, height).positionCentered().resizable().build();

    sdl::render::Renderer renderer = window.createRenderer().accelerated().build();

    chess::ChessGame activeGame(GRID_NCOLS, GRID_NROWS);
    activeGame.redraw(renderer, width, height, MARGIN, GRID_NCOLS, GRID_NROWS);

    bool run = true;
    while (run)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_WINDOWEVENT)
            {
                SDL_WindowEvent we = e.window;
                if (we.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    width = we.data1;
                    height = we.data2;
                }
            }
            else if (e.type == SDL_RENDER_TARGETS_RESET)
            {
                // refresh all textures
                activeGame.redraw(renderer, width, height, MARGIN, GRID_NCOLS, GRID_NROWS);
            }
            else if (e.type == SDL_QUIT)
            {
                run = false;
                break;
            }
        }

        renderer.setDrawColor(BG_COLOR);
        renderer.clear();

        activeGame.displayGrid(renderer);

        renderer.present();
    }

    return 0;
}
