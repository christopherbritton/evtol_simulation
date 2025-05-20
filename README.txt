EVTOL Simulation

This project simulates a fleet of electric vertical takeoff and landing (EVTOL) aircraft. It models randomized vehicle behavior, charging needs, fault occurrence, and collects usage statistics.

Features:
- Multiple EVTOL types with customizable profiles
- Randomized charging and fault logic
- Charger manager with port constraints
- Fleet statistics and fault tracking
- Cross-platform build and test system (CMake, bash, batch)
- Unit tests for all major components

Getting Started:

Linux/macOS:
$ chmod +x setup.sh
$ ./setup.sh

Windows (MinGW):
> build_and_run.bat

Structure:
- EVTOL, FleetManager, ChargerManager: Core logic
- StatisticsTracker, FaultManager: Data analysis
- tests/: Unit tests
- VehicleProfile.hpp, VehicleType.hpp: Shared type definitions
