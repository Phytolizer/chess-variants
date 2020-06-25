/**
 * @file main.cc
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief The main file
 * @date 2020-06-24
 */

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <chess/gridSquare.hh>
#include <cmath>
#include <iostream>
#include <sdl_wrapper/context.hh>
#include <sdl_wrapper/render/renderer.hh>
#include <sdl_wrapper/render/texture.hh>
#include <sdl_wrapper/video/window.hh>
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
    int xGridAmount = 8;
    int yGridAmount = 8;
    int squareSize = ((100 - margin * 2) * std::min(height/yGridAmount, width/xGridAmount) / 100);
    int xDisplacement = (width - squareSize * xGridAmount) / 2;
    int yDisplacement = (height - squareSize * yGridAmount) / 2;

    sdl::Context sdlContext;
    sdl::video::Context videoContext = sdlContext.initVideo();

    sdl::video::Window window =
        videoContext.createWindow("test window", 0, 0, width, height).positionCentered().resizable().build();

    sdl::render::Renderer renderer = window.createRenderer().accelerated().build();

    std::vector<chess::GridSquare *> grid(xGridAmount * yGridAmount);
    int i = 0;
    for (int x = 0; x < xGridAmount; x++)
    {
        for (int y = 0; y < yGridAmount; y++)
        {
            if (x % 2 == y % 2)
            {
                grid[i++] = new chess::GridSquare(x, y, {0xaa, 0xaa, 0xaa, 0xff}, true);
            }
            else
            {
                grid[i++] = new chess::GridSquare(x, y, {0x77, 0x77, 0x77, 0xff}, true);
            }
        }
    }

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
                    squareSize = ((100 - margin * 2) * std::min(height/yGridAmount, width/xGridAmount) / 100);
                    xDisplacement = (width - squareSize * xGridAmount) / 2;
                    yDisplacement = (height - squareSize * yGridAmount) / 2;
                }
            }
        }

        renderer.setDrawColor({0x44, 0x44, 0x44, 0xff});
        renderer.clear();

        for (auto &g : grid)
        {
            g->display(renderer, squareSize, xDisplacement, yDisplacement);
        }

        renderer.present();
    }

    return 0;
}
