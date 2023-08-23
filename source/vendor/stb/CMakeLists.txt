cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(stb)

# Build glad from source
include_directories(.)

file(GLOB stb_src "${PROJECT_SOURCE_DIR}/*.cpp")

add_library(stb ${stb_src})
