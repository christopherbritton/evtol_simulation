#include "FleetManager.hpp"
#include <iostream>
#include <cassert>

// Test that fleet of 20 vehicles is created properly
bool testAddVehicle() {
    std::vector<VehicleType> types = {VehicleType::Alpha};
    std::map<VehicleType, VehicleProfile> profiles = {
        {VehicleType::Alpha, {100, 50, 1.0, 0.5, 3, 0.01}}
    };
    std::default_random_engine rng;
    FleetManager fm(types, rng, profiles);

    if (fm.getFleet().size() != 20) {
        std::cerr << "❌ testAddVehicle failed: Expected 20 EVTOLs, got " << fm.getFleet().size() << "\n";
        return false;
    }
    std::cout << "✅ testAddVehicle passed\n";
    return true;
}

// Test that getFleet returns a valid non-empty fleet
bool testGetFleet() {
    std::vector<VehicleType> types = {VehicleType::Bravo};
    std::map<VehicleType, VehicleProfile> profiles = {
        {VehicleType::Bravo, {120, 60, 1.2, 0.6, 4, 0.02}}
    };
    std::default_random_engine rng;
    FleetManager fm(types, rng, profiles);

    const auto& fleet = fm.getFleet();
    if (fleet.empty()) {
        std::cerr << "❌ testGetFleet failed: Fleet should not be empty\n";
        return false;
    }
    std::cout << "✅ testGetFleet passed\n";
    return true;
}

// Entry point to run and summarize all FleetManager tests
int main() {
    int failed = 0;
    if (!testAddVehicle()) {
        std::cerr << "FAILED: testAddVehicle\n";
        ++failed;
    }
    if (!testGetFleet()) {
        std::cerr << "FAILED: testGetFleet\n";
        ++failed;
    }

    if (failed == 0) {
        std::cout << "\n All FleetManager tests passed\n";
        return 0;
    } else {
        std::cerr << "\n❌ " << failed << " FleetManager test(s) failed\n";
        return 1;
    }
}
