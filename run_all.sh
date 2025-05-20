#!/bin/bash
set -e

# Ensure tests and simulation are built
echo "🔧 Building all unit test targets..."
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
echo -e "\n🧪 Running unit tests..."
for test in "${TESTS[@]}"; do
    echo -e "\n🔷 Running: $test"
    ./build/$test || {
        echo -e "\n❌ FAILED  : $test"
        exit 1
    }
    echo -e "✅ PASSED  : $test"
done

# Run the simulation with output enabled
echo -e "\n🚀 Running: evtol_simulation"
EVTOL_MODE=SIMULATION ./build/evtol_simulation

echo -e "\n✅ All unit tests and main simulation completed successfully."
