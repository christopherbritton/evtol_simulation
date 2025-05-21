#!/bin/bash
set -e

# Rebuild everything
echo -e "\n🔄 Rebuilding everything..."
rm -rf build
cmake -Bbuild .
cmake --build build --target all

# Run all test executables explicitly
echo -e "\n✅ Running unit tests..."

declare -a TESTS=(
  "test_evtol"
  "test_charger_manager"
  "test_fault_manager"
  "test_fleet_manager"
  "test_statistics_tracker"
)

FAILED=0

for test in "${TESTS[@]}"; do
  exe="./build/${test}"
  echo -e "\n Running: $test"
  if [[ -x "$exe" ]]; then
    $exe
    if [[ $? -ne 0 ]]; then
      echo -e "❌ $test FAILED"
      FAILED=1
    else
      echo -e "✅ [ PASSED ] $test"
    fi
  else
    echo -e "❌ [ MISSING ] $test executable not found at $exe"
    FAILED=1
  fi
done

# Run main simulation
echo -e "\n📊 Running main simulation with stats output..."
export EVTOL_MODE=SIMULATION
./build/evtol_simulation

if [[ $FAILED -eq 0 ]]; then
  echo -e "\n🎉 All tests and main simulation completed successfully."
else
  echo -e "\n❌ One or more tests failed."
  exit 1
fi
