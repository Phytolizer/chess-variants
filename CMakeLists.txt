cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

project(chessvariants)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cc")

add_executable(chessvariants ${SOURCES})
target_link_libraries(chessvariants SDL2 SDL2_image SDL2_ttf SDL2_mixer)
target_include_directories(chessvariants PRIVATE src)
target_include_directories(chessvariants PRIVATE include)

if(MSVC)
  target_compile_options(chessvariants PRIVATE /W4)
else()
  target_compile_options(chessvariants PRIVATE -Wall -Wextra -pedantic)
endif()

target_link_options(chessvariants PRIVATE "-L${CMAKE_CURRENT_LIST_DIR}/build")
