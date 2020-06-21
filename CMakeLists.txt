cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

project(chessvariants)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cc")

add_executable(chessvariants ${SOURCES})
target_link_libraries(chessvariants SDL2 SDL_image SDL_ttf)
target_include_directories(chessvariants PRIVATE src)

if(MSVC)
  target_compile_options(chessvariants PRIVATE /W4 /WX)
else()
  target_compile_options(chessvariants PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
