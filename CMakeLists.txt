cmake_minimum_required(VERSION 3.15)

project(chessvariants)

file(GLOB_RECURSE SOURCES "src/*.cc")

add_executable(chessvariants ${SOURCES})
target_link_libraries(chessvariants SDL2 SDL_image SDL_ttf)