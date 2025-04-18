cmake_minimum_required(VERSION 3.6)
project(cccnake C)

# Put the executable file in the bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Make it possible to put the header files in the include folder
include_directories(${CMAKE_SOURCE_DIR}/include)

# Export compile commands to the IDE's language server
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(cccnake 
    src/main.c
    src/logic.c
)
