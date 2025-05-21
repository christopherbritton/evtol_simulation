cmake_minimum_required(VERSION 3.10)
project(EVTOLSimulation)

set(CMAKE_CXX_STANDARD 17)

# Define source files shared across simulation and tests
set(SOURCES
    src/main.cpp
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

# Add shared simulation logic as a library
add_library(core_sources
    src/EVTOL.cpp
    src/ChargerManager.cpp
    src/FaultManager.cpp
    src/FleetManager.cpp
    src/StatisticsTracker.cpp
)

# Make headers visible to all targets
target_include_directories(core_sources PRIVATE common)
include_directories(common)

# Main simulation build
add_executable(evtol_simulation ${SOURCES} ${HEADERS})
target_link_libraries(evtol_simulation PRIVATE core_sources)

# Unit test targets
add_executable(test_evtol tests/test_evtol.cpp)
target_include_directories(test_evtol PRIVATE common)
target_link_libraries(test_evtol PRIVATE core_sources)

add_executable(test_charger_manager tests/test_charger_manager.cpp)
target_include_directories(test_charger_manager PRIVATE common)
target_link_libraries(test_charger_manager PRIVATE core_sources)

add_executable(test_fault_manager tests/test_fault_manager.cpp)
target_include_directories(test_fault_manager PRIVATE common)
target_link_libraries(test_fault_manager PRIVATE core_sources)

add_executable(test_fleet_manager tests/test_fleet_manager.cpp)
target_include_directories(test_fleet_manager PRIVATE common)
target_link_libraries(test_fleet_manager PRIVATE core_sources)

add_executable(test_statistics_tracker tests/test_statistics_tracker.cpp)
target_include_directories(test_statistics_tracker PRIVATE common)
target_link_libraries(test_statistics_tracker PRIVATE core_sources)

# Optional: Custom targets for unified execution
add_custom_target(run_all
    COMMAND test_evtol
    COMMAND test_charger_manager
    COMMAND test_fault_manager
    COMMAND test_fleet_manager
    COMMAND test_statistics_tracker
    COMMAND evtol_simulation
)
