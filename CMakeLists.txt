# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and standard version
project(EVTOLSimulation)
set(CMAKE_CXX_STANDARD 17)

# Main simulation source file
set(SOURCES src/main.cpp)

# All header files used in simulation and tests
set(HEADERS
    common/EVTOL.hpp
    common/ChargerManager.hpp
    common/FaultManager.hpp
    common/FleetManager.hpp
    common/VehicleType.hpp
    common/VehicleProfile.hpp
    common/StatisticsTracker.hpp
)

# Define core source files to compile as a shared library between tests and main
add_library(core_sources
    src/EVTOL.cpp
    src/ChargerManager.cpp
    src/FaultManager.cpp
    src/FleetManager.cpp
    src/StatisticsTracker.cpp
)

# Make headers in 'common' directory available to core_sources
target_include_directories(core_sources PRIVATE common)
include_directories(common)

# Build the main EVTOL simulation executable
add_executable(evtol_simulation ${SOURCES} ${HEADERS})
# Link the core logic library with the main executable
target_link_libraries(evtol_simulation PRIVATE core_sources)

# Define and configure each unit test executable
# EVTOL unit test
add_executable(test_evtol tests/test_evtol.cpp)
target_include_directories(test_evtol PRIVATE common)
target_link_libraries(test_evtol PRIVATE core_sources)

# ChargerManager unit test
add_executable(test_charger_manager tests/test_charger_manager.cpp)
target_include_directories(test_charger_manager PRIVATE common)
target_link_libraries(test_charger_manager PRIVATE core_sources)

# FaultManager unit test
add_executable(test_fault_manager tests/test_fault_manager.cpp)
target_include_directories(test_fault_manager PRIVATE common)
target_link_libraries(test_fault_manager PRIVATE core_sources)

# FleetManager unit test
add_executable(test_fleet_manager tests/test_fleet_manager.cpp)
target_include_directories(test_fleet_manager PRIVATE common)
target_link_libraries(test_fleet_manager PRIVATE core_sources)

# StatisticsTracker unit test
add_executable(test_statistics_tracker tests/test_statistics_tracker.cpp)
target_include_directories(test_statistics_tracker PRIVATE common)
target_link_libraries(test_statistics_tracker PRIVATE core_sources)

# Custom target to run all tests and simulation in sequence
add_custom_target(run_all
    COMMAND test_evtol
    COMMAND test_charger_manager
    COMMAND test_fault_manager
    COMMAND test_fleet_manager
    COMMAND test_statistics_tracker
    COMMAND evtol_simulation
)
