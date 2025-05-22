#!/bin/bash

# run_simulation.sh — Build and run only the evtol_simulation target

# Exit on any error
set -e

echo " Configuring and building evtol_simulation..."
cmake -S . -B build
cmake --build build --target evtol_simulation

echo -e "\n Running evtol_simulation..."
./build/evtol_simulation

echo -e "\n✅ Simulation completed successfully."
