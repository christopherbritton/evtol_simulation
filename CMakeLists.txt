cmake_minimum_required(VERSION 3.10)
project(EVTOL_Simulation)

set(CMAKE_CXX_STANDARD 17)

# Include header directories
include_directories(
    ${CMAKE_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}/src
)

# Main executable sources
set(SRC_FILES
    src/FleetManager.cpp
    src/Statistics.cpp
    src/StatisticsReporter.cpp
    src/AlphaEVTOL.cpp
    src/BravoEVTOL.cpp
    src/CharlieEVTOL.cpp
    src/DeltaEVTOL.cpp
    src/EchoEVTOL.cpp
    src/main.cpp       # Only used for main simulation
)

# Build main simulation
add_executable(evtol_sim ${SRC_FILES})

# Unit test target (excluding main.cpp)
set(TEST_SRC_FILES
    src/FleetManager.cpp
    src/Statistics.cpp
    src/StatisticsReporter.cpp
    src/AlphaEVTOL.cpp
    src/BravoEVTOL.cpp
    src/CharlieEVTOL.cpp
    src/DeltaEVTOL.cpp
    src/EchoEVTOL.cpp
    tests/test_evtol_methods.cpp
)

add_executable(test_evtol_methods ${TEST_SRC_FILES})
