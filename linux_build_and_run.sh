#!/bin/bash

set -e

# Create and enter build directory
mkdir -p build
cd build

# Generate build system
cmake ..

# Build everything (main + tests)
make

# Run simulation
echo "Running main simulation..."
./evtol_simulation

# Run unit tests
echo "Running unit tests..."
ctest --output-on-failure
