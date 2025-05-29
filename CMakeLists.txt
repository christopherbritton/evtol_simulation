# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(evtol_simulation)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)
include_directories(tests)
include_directories(common)

# Source files
file(GLOB SOURCES
    src/*.cpp
)

# Exclude main.cpp from test sources
set(TEST_SOURCES ${SOURCES})
list(REMOVE_ITEM TEST_SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)

# Main simulation executable
add_executable(evtol_simulation src/main.cpp ${SOURCES})

# Unit test executables
add_executable(test_evtol tests/test_evtol.cpp ${TEST_SOURCES})
add_executable(test_charger_manager tests/test_charger_manager.cpp ${TEST_SOURCES})
add_executable(test_fault_manager tests/test_fault_manager.cpp ${TEST_SOURCES})
add_executable(test_fleet_manager tests/test_fleet_manager.cpp ${TEST_SOURCES})
add_executable(test_statistics_tracker tests/test_statistics_tracker.cpp ${TEST_SOURCES})

# Enable testing and register tests
enable_testing()
add_test(NAME evtol_simulation COMMAND evtol_simulation)
add_test(NAME test_evtol COMMAND test_evtol)
add_test(NAME test_charger_manager COMMAND test_charger_manager)
add_test(NAME test_fault_manager COMMAND test_fault_manager)
add_test(NAME test_fleet_manager COMMAND test_fleet_manager)
add_test(NAME test_statistics_tracker COMMAND test_statistics_tracker)

# Optional: Add custom target to build and run all tests
add_custom_target(run_all_tests ALL
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_evtol test_charger_manager test_fault_manager test_fleet_manager test_statistics_tracker
)

# Link libraries (if needed)
# target_link_libraries(evtol_simulation ...)
# target_link_libraries(test_evtol ...)
# etc.

