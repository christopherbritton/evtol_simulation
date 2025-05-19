cmake_minimum_required(VERSION 3.10)
project(JobyAviationSimulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(.)

# Source files
set(SOURCES
    EVTOL.cpp
    FleetManager.cpp
    ChargerManager.cpp
    StatisticsTracker.cpp
    FaultManager.cpp
)

# Test executables
add_executable(test_evtol tests/test_evtol.cpp ${SOURCES})
add_executable(test_fleetmanager tests/test_fleetmanager.cpp ${SOURCES})
add_executable(test_chargermanager tests/test_chargermanager.cpp ${SOURCES})
add_executable(test_fault_manager tests/test_faultmanager.cpp ${SOURCES})
add_executable(test_statisticstracker tests/test_statisticstracker.cpp ${SOURCES})

# Enable testing
enable_testing()
add_test(NAME TestEVTOL COMMAND test_evtol)
add_test(NAME TestFleetManager COMMAND test_fleetmanager)
add_test(NAME TestChargerManager COMMAND test_chargermanager)
add_test(NAME TestFaultManager COMMAND test_fault_manager)
add_test(NAME TestStatisticsTracker COMMAND test_statisticstracker)
