#include "FleetManager.hpp"
#include "VehicleType.hpp"
#include "VehicleProfile.hpp"
#include <random>
#include <iostream>
#include <cassert>

void testFleetManager() {
    std::vector<VehicleType> types = {VehicleType::Alpha};
    std::map<VehicleType, VehicleProfile> profiles = {
        {VehicleType::Alpha, {150, 100, 1.0, 0.5, 4, 0.01}}
    };

    std::default_random_engine rng(42);
    FleetManager fm(types, rng, profiles);
    assert(fm.getFleet().size() == 20);
    std::cout << "FleetManager tests passed.\n";
}

int main() {
    testFleetManager();
    return 0;
}
