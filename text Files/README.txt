# EVTOL Simulation Project

This project simulates a fleet of electric vertical takeoff and landing (EVTOL) aircraft, 
including functionality for flight simulation, fault tracking, charging management, and performance 
statistics. It also includes individual unit tests for each core component.

---

## Project Structure

- `src/` - Main source files
- `common/` - Shared headers
- `tests/` - Individual unit test files
- `build/` - CMake-generated build output
- `CMakeLists.txt` - Build configuration
- `run_all.sh` - Builds and runs all unit tests and the main simulation
- `run_simulation.sh` - Builds and runs only the main simulation
- `run_all_tests.sh` - Builds and runs all unit tests

---

## Build & Run Instructions

 1. Build & run all tests and simulation:
```bash
./run_all.sh
