cmake_minimum_required(VERSION 3.10)
project(EVTOL_Simulation)

set(CMAKE_CXX_STANDARD 17)

# Include directories for headers
include_directories(
    ${CMAKE_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}/src
)

# Gather all source files
file(GLOB SRC_FILES src/*.cpp)
list(REMOVE_ITEM SRC_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp)

# Main simulation executable
add_executable(evtol_sim ${SRC_FILES} src/main.cpp)

# Unit test executable (excluding main.cpp)
add_executable(test_evtol_methods tests/test_evtol_methods.cpp ${SRC_FILES})