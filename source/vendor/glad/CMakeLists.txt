cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(glad)

# Build glad from source
include_directories(.)

file(GLOB glad_src "${PROJECT_SOURCE_DIR}/glad/src/*.c")

add_library(glad ${glad_src})
