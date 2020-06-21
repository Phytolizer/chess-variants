/// @file main.cc
/// @author Kyle Coffey

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

    return 0;
}