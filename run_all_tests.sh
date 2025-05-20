#!/bin/bash
set -e

# Ensure tests are built first
echo "Building all unit test targets..."
cmake -S . -B build
cmake --build build --target all

# Define test executables
TESTS=(
    "test_evtol"
    "test_charger_manager"
    "test_fault_manager"
    "test_fleet_manager"
    "test_statistics_tracker"
)

# Run each test
echo -e "\nRunning unit tests:"
for test in "${TESTS[@]}"; do
    echo -e "\n[ RUNNING ] $test"
    ./build/$test || {
        echo -e "[ FAILED  ] $test"
        exit 1
    }
    echo "[ PASSED  ] $test"
done

echo -e "\n✅ All unit tests passed successfully!"
