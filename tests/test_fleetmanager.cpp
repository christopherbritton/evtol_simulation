
#include "FleetManager.hpp"
#include "EVTOL.hpp"
#include <random>
#include <iostream>

// Simple test to ensure FleetManager constructs the correct number of EVTOLs
int main() {
    std::vector<VehicleType> types = {
        VehicleType::Alpha,
        VehicleType::Bravo,
        VehicleType::Charlie,
        VehicleType::Delta,
        VehicleType::Echo
    };

    std::map<VehicleType, VehicleProfile> profiles = {
        { VehicleType::Alpha,   { 150, 100, 0.8, 0.5, 4, 0.01 } },
        { VehicleType::Bravo,   { 120, 120, 0.7, 0.75, 5, 0.015 } },
        { VehicleType::Charlie, { 100, 130, 0.6, 1.0, 6, 0.02 } },
        { VehicleType::Delta,   { 180, 80, 1.0, 0.5, 2, 0.005 } },
        { VehicleType::Echo,    { 110, 140, 0.9, 1.25, 7, 0.025 } }
    };

    std::default_random_engine rng(42);
    FleetManager manager(types, rng, profiles);
    std::vector<EVTOL>& fleet = manager.getFleet();

    std::cout << "FleetManager test passed: Fleet size = " << fleet.size() << "\n";
    return 0;
}
