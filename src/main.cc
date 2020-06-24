/// @file main.cc
/// @author Kyle Coffey

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <cmath>
#include <iostream>
#include <sdl_wrapper/context.hh>
#include <sdl_wrapper/render/renderer.hh>
#include <sdl_wrapper/render/texture.hh>
#include <sdl_wrapper/video/window.hh>

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
    int gridSize = 8;
    float playSize = 4 * height / 5;

    sdl::Context sdlContext;
    sdl::video::Context videoContext = sdlContext.initVideo();

    sdl::video::Window window =
        videoContext.createWindow("test window", 0, 0, width, height).positionCentered().resizable().build();

    sdl::render::Renderer renderer = window.createRenderer().accelerated().build();

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
                    if (width > height)
                    {
                        playSize = 4 * height / 5;
                    }
                    else
                    {
                        playSize = 4 * width / 5;
                    }
                }
            }
        }

        renderer.setDrawColor({0x44, 0x44, 0x44, 0xff});
        renderer.clear();

        drawChessBoard(renderer, window.getPixelFormat());
        if (playSize > 8)
        {
            for (int h = 0; h < gridSize; h++)
            {
                for (int w = 0; w < gridSize; w++)
                {
                    if (h % 2 == w % 2)
                    {
                        renderer.setDrawColor({0xbb, 0xbb, 0xbb, 0xff});
                    }
                    else
                    {
                        renderer.setDrawColor({0x77, 0x77, 0x77, 0xff});
                    }
                    renderer.fillRect({static_cast<int>(ceil((width - playSize) / 2 + w * playSize / gridSize)),
                                       static_cast<int>(ceil((height - playSize) / 2 + h * playSize / gridSize)),
                                       static_cast<int>(ceil(playSize / gridSize)),
                                       static_cast<int>(ceil(playSize / gridSize))});
                }
            }
        }
        renderer.present();
    }

    return 0;
}
