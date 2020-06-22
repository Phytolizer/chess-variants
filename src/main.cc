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
    sdl::Context sdlContext;
    auto videoContext = sdlContext.initVideo();

    auto window = videoContext.createWindow("test window", 0, 0, 100, 100).positionCentered().build();

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
        }
    }

    return 0;
}