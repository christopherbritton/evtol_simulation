#!/bin/bash
set -e
mkdir -p build
cd build
cmake ..
make
echo "Build complete."
./evtol_simulation || echo "Executable not found: main"
