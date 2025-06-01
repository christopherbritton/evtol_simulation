#!/bin/bash
set -e

BUILD_DIR="build_tests"
EXECUTABLE="test_evtol_methods"

echo "🧹 Cleaning previous test build artifacts..."
rm -rf "$BUILD_DIR"
mkdir "$BUILD_DIR"
cd "$BUILD_DIR"

echo "⚙️ Configuring CMake..."
cmake ..

echo "🛠️ Building unit tests..."
make "$EXECUTABLE"

echo "🚀 Running unit tests..."
./"$EXECUTABLE"