cmake_minimum_required(VERSION 3.6)
project(cccnake C)

# Put the executable file in the bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Make it possible to put the header files in the include folder
include_directories(${CMAKE_SOURCE_DIR}/include)

# Include FetchContent to make Raylib work
include(FetchContent)

# Prevents unnecessary downloads
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

# Makes FetchContent able to reach Raylib
FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

# Makes Raylib available 
FetchContent_MakeAvailable(raylib)

# Export compile commands to the IDE's language server
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(cccnake 
    src/main.c
    src/logic.c
)

target_link_libraries(cccnake PRIVATE raylib)
