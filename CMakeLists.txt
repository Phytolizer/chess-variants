cmake_minimum_required(VERSION 3.15)

project(chessvariants)

file(GLOB_RECURSE SOURCES "src/*.cc")

add_executable(chessvariants ${SOURCES})