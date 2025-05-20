#!/bin/bash

# run_all.sh — Build and run all unit tests + main simulation

# Exit immediately if any command fails
set -e

# Step 1: Configure and build all targets
echo "🔧 Configuring and building all targets..."
cmake -S . -B build
cmake --build build --target all

# Step 2: Run all tests and simulation
echo -e "\n🚀 Running unit tests and simulation..."

TESTS=(
  "test_evtol"
  "test_charger_manager"
  "test_fault_manager"
  "test_fleet_manager"
  "test_statistics_tracker"
)

for test in "${TESTS[@]}"; do
  echo -e "\n▶️ Running: $test"
  ./build/$test
done

# Step 3: Run the main simulation
echo -e "\n🎯 Running: evtol_simulation"
./build/evtol_simulation

echo -e "\n✅ All unit tests and main simulation completed successfully."
