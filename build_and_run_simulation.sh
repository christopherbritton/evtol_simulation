#!/bin/bash

set -e  # Exit immediately on error

BUILD_DIR="build"
EXECUTABLE="evtol_sim"

echo "🔄 Cleaning previous build artifacts..."
rm -rf "$BUILD_DIR"
mkdir "$BUILD_DIR"
cd "$BUILD_DIR"

echo "🔧 Configuring CMake..."
cmake ..

echo "⚙️ Building project..."
make -j$(nproc)

echo "🚀 Running simulation..."
./$EXECUTABLE

echo "✅ Simulation complete."
