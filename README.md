# EVTOL Simulation

## Overview
This simulation models a fleet of electric vertical take-off and landing (EVTOL) vehicles with distinct performance characteristics. Each vehicle type (Alpha, Bravo, Charlie, Delta, Echo) inherits from a common EVTOL interface and overrides behavior such as flight energy usage and charging.

## Features
- Object-oriented design using inheritance and polymorphism.
- Simulation of flights, energy usage, charging logic, and random fault generation.
- Fleet statistics aggregation by vehicle type.
- Unit testing for each class and method.

## Build Instructions
1. Ensure a C++17-compatible compiler is installed.
2. Run `./build_and_run_simulation.sh` to clean, build, and execute the simulation.
3. Run `./build_and_run_unit_tests.sh` to build and execute unit tests.

## Configuration
All configurable parameters are located in `Config.hpp`, including:
- `MaxChargers`
- Vehicle battery capacity
- Cruise speed, charge time, and fault probability for each vehicle type

## Simulation Flow
1. A fleet of 20 EVTOLs (randomly distributed across 5 types) is generated.
2. Each simulation step advances time and simulates:
   - Flight duration and energy usage
   - Fault generation (Bernoulli trial)
   - Battery charge level checks and queueing
   - Charging of vehicles using a fixed number of available chargers
3. Statistics such as total flight hours, faults, and passenger-miles are printed to console.

## Performance Notes
- Time complexity per step: `O(N + C)`
- Sequential simulation (can be parallelized for scale)

## Source Structure
- `main.cpp`: Launches the simulation
- `FleetManager.*`: Controls simulation loop and statistics
- `EVTOL.hpp`: Abstract base class
- `AlphaEVTOL.cpp/hpp` … `EchoEVTOL.cpp/hpp`: Concrete vehicle implementations
- `Config.hpp`: Parameter values
- `test_*.cpp`: Unit test files

## Extension Ideas
- Add visualization or logging of flight paths
- Introduce scheduling logic for fleet dispatch
- Expand vehicle models with weather or payload effects
