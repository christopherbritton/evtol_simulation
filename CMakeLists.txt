cmake_minimum_required(VERSION 3.10)
project(EVTOLSimulation)
set(CMAKE_CXX_STANDARD 17)

# Define common include path
include_directories(common)

# Define main source files
set(SOURCES
    src/EVTOL.cpp
    src/FleetManager.cpp
    src/ChargerManager.cpp
    src/FaultManager.cpp
    src/StatisticsTracker.cpp
    src/main.cpp
)

# Main simulation executable
add_executable(evtol_simulation ${SOURCES})

# Enable unit testing
enable_testing()

# -------------------- Test: EVTOL --------------------
add_executable(test_evtol 
    tests/test_evtol.cpp 
    src/EVTOL.cpp
)
target_include_directories(test_evtol PRIVATE common)
add_test(NAME test_evtol COMMAND test_evtol)

# -------------------- Test: FleetManager --------------------
add_executable(test_fleetmanager 
    tests/test_fleetmanager.cpp 
    src/FleetManager.cpp 
    src/EVTOL.cpp
)
target_include_directories(test_fleetmanager PRIVATE common)
add_test(NAME test_fleetmanager COMMAND test_fleetmanager)

# -------------------- Test: ChargerManager --------------------
add_executable(test_chargermanager 
    tests/test_chargermanager.cpp 
    src/ChargerManager.cpp 
    src/EVTOL.cpp
)
target_include_directories(test_chargermanager PRIVATE common)
add_test(NAME test_chargermanager COMMAND test_chargermanager)

# -------------------- Test: FaultManager --------------------
add_executable(test_fault_manager 
    tests/test_faultmanager.cpp 
    src/FaultManager.cpp 
    src/EVTOL.cpp
)
target_include_directories(test_fault_manager PRIVATE common)
add_test(NAME test_fault_manager COMMAND test_fault_manager)

# -------------------- Test: StatisticsTracker --------------------
add_executable(test_statisticstracker 
    tests/test_statisticstracker.cpp 
    src/StatisticsTracker.cpp 
    src/EVTOL.cpp
)
target_include_directories(test_statisticstracker PRIVATE common)
add_test(NAME test_statisticstracker COMMAND test_statisticstracker)