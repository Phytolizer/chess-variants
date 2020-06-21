/// @file main.cc
/// @author Kyle Coffey

#include <SDL2/SDL.h>
#include <iostream>

using std::cerr;

/**
 * @brief The main function.
 *
 * @return int The exit status code. 
 * 0 for success, non-zero for failure.
 */
int main()
{
    // initialize SDL

    /// SDL's init flags.
    Uint32 flags = SDL_INIT_VIDEO;

    /// The error code from SDL functions. I hate C
    int code = SDL_Init(flags);
    if (code != 0) 
    {
        cerr << "Could not initialize SDL: " << SDL_GetError() << "\n";
        return code;
    }

    SDL_Quit();
    return 0;
}