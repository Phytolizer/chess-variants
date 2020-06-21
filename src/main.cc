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
    int code = SDL_Init(0);
    if (code != 0) 
    {
        cerr << "Could not initialize SDL: " << SDL_GetError() << "\n";
        return code;
    }

    SDL_Quit();
    return 0;
}