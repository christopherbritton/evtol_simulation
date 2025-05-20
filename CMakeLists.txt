# CMakeLists.txt (Updated to build separate test executables and enable test output)

cmake_minimum_required(VERSION 3.10)
project(EVTOLSimulation)

set(CMAKE_CXX_STANDARD 17)

# Define source files
set(SOURCES
    src/main.cpp
    src/EVTOL.cpp
    src/FleetManager.cpp
    src/ChargerManager.cpp
    src/FaultManager.cpp
    src/StatisticsTracker.cpp
)

# Define header files
set(HEADERS
    common/EVTOL.hpp
    common/VehicleProfile.hpp
    common/VehicleType.hpp
    common/ChargerManager.hpp
    common/FaultManager.hpp
    common/FleetManager.hpp
    common/StatisticsTracker.hpp
)

# Main simulation build
add_executable(evtol_simulation ${SOURCES} ${HEADERS})

# Link common headers for main simulation
target_include_directories(evtol_simulation PRIVATE common)

# Individual unit test executables
add_executable(test_evtol tests/test_evtol.cpp src/EVTOL.cpp)
add_executable(test_charger_manager tests/test_charger_manager.cpp src/ChargerManager.cpp src/EVTOL.cpp)
add_executable(test_fault_manager tests/test_fault_manager.cpp src/FaultManager.cpp)
add_executable(test_fleet_manager tests/test_fleet_manager.cpp src/FleetManager.cpp src/EVTOL.cpp)
add_executable(test_statistics_tracker tests/test_statistics_tracker.cpp src/StatisticsTracker.cpp)

# Include common headers for all test targets
target_include_directories(test_evtol PRIVATE common)
target_include_directories(test_charger_manager PRIVATE common)
target_include_directories(test_fault_manager PRIVATE common)
target_include_directories(test_fleet_manager PRIVATE common)
target_include_directories(test_statistics_tracker PRIVATE common)

# Add custom target to run all tests and main simulation together
add_custom_target(run_all
    COMMAND test_evtol
    COMMAND test_charger_manager
    COMMAND test_fault_manager
    COMMAND test_fleet_manager
    COMMAND test_statistics_tracker
    COMMAND evtol_simulation
)

# Add custom command for bash script use
add_custom_command(TARGET run_all POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "\nAll tests and main simulation have run successfully."
)