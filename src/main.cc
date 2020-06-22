/// @file main.cc
/// @author Kyle Coffey

#include <SDL2/SDL_events.h>
#include <iostream>
#include <sdl_wrapper/context.hh>
#include <sdl_wrapper/video/window.hh>

using std::cerr;

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
    int playSize = 4 * height / 5;

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

        renderer.clear();
        bool BGcolor = false;
        if (playSize > 8)
        {
            for (int h = 0; h <= playSize; h += playSize / 8)
            {
                for (int w = 0; w <= playSize; w += playSize / 8)
                {
                    if (BGcolor)
                    {
                        renderer.setDrawColor({0xbb, 0xbb, 0xbb, 0xff});
                    }
                    else
                    {
                        renderer.setDrawColor({0x77, 0x77, 0x77, 0xff});
                    }
                    BGcolor = !BGcolor;
                    renderer.fillRect({(width - playSize) / 2 + w - playSize / 8, (height - playSize) / 2 + h - playSize / 8, w, h});
                }
            }
            renderer.setDrawColor({0x44, 0x44, 0x44, 0xff});
            renderer.fillRect({-2, -2, width + 4, (height - playSize) / 2 + 2});
            renderer.fillRect({-2, -2, (width - playSize) / 2 + 2, height + 4});
            renderer.fillRect({(width - playSize) / 2 + playSize, -2, (width - playSize) / 2 + 2, height + 4});
            renderer.fillRect({-2, (height - playSize) / 2 + playSize, width + 4, (height - playSize) / 2 + 2});
        }
        renderer.present();
    }

    return 0;
}
