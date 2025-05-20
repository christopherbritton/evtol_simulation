#!/bin/bash
# run_all.sh — Build and run all unit tests and simulation

# Exit on any failure
set -e

echo "🛠️ Building all targets..."
cmake -S . -B build
cmake --build build --target all

# Define and run unit tests
TESTS=(
  "test_evtol"
  "test_charger_manager"
  "test_fault_manager"
  "test_fleet_manager"
  "test_statistics_tracker"
)

echo -e "\n Running unit tests..."
for test in "${TESTS[@]}"; do
  echo -e "\n Running: $test"
  ./build/$test || {
    echo -e "❌ [ FAILED  ] $test"
    exit 1
  }
  echo -e "✅ [ PASSED  ] $test"
done

# Run the simulation with statistics output enabled
echo -e "\n🚀 Running: evtol_simulation with stats (EVTOL_MODE=SIMULATION)"
env EVTOL_MODE=SIMULATION ./build/evtol_simulation

echo -e "\n✅ All unit tests and main simulation completed successfully."
