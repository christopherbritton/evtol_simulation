#include "FleetManager.hpp"
#include <iostream>
#include <cassert>

// Constants for testing
const int expectedFleetSize = 20;
const VehicleType testType1 = VehicleType::Alpha;
const VehicleType testType2 = VehicleType::Bravo;
const VehicleProfile testProfile1 = {100, 50, 1.0, 0.5, 3, 0.01};
const VehicleProfile testProfile2 = {120, 60, 1.2, 0.6, 4, 0.02};

// Test that fleet of 20 vehicles is created properly
bool testAddVehicle() {
    std::vector<VehicleType> types = {testType1};
    std::map<VehicleType, VehicleProfile> profiles = {
        {testType1, testProfile1}
    };
    std::default_random_engine rng;
    FleetManager fm(types, rng, profiles);

    if (fm.getFleet().size() != expectedFleetSize) {
        std::cerr << "❌ testAddVehicle failed: Expected " << expectedFleetSize << " EVTOLs, got " << fm.getFleet().size() << "\n";
        return false;
    }
    std::cout << "✅ testAddVehicle passed\n";
    return true;
}

// Test that getFleet returns a valid non-empty fleet
bool testGetFleet() {
    std::vector<VehicleType> types = {testType2};
    std::map<VehicleType, VehicleProfile> profiles = {
        {testType2, testProfile2}
    };
    std::default_random_engine rng;
    FleetManager fm(types, rng, profiles);

    const std::vector<EVTOL>& fleet = fm.getFleet();
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
        std::cout << "\n✅ All FleetManager tests passed\n";
        return 0;
    } else {
        std::cerr << "\n❌ " << failed << " FleetManager test(s) failed\n";
        return 1;
    }
}