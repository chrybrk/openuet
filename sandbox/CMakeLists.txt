cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(sandbox VERSION 0.1.0 LANGUAGES CXX C)

#########################################
#				Defination				#
#########################################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_compile_definitions(JUICE_PLATFORM_LINUX)
endif()

if(WIN32)
    add_compile_definitions(JUICE_PLATFORM_WINDOW)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++17")
	add_compile_definitions(SQ_RELEASE)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -ggdb3 -Wall -std=c++17")
	add_compile_definitions(SQ_DEBUG)
endif()

#########################################
#				Includes				#
#########################################
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}")
include_directories(${SOURCE_DIR})


#########################################
#			  Build Juice				#
#########################################
file(GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.cpp")

add_executable(sandbox ${SOURCE_FILES})
target_link_libraries(sandbox "openuet")