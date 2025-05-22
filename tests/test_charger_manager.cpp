#include "ChargerManager.hpp"
#include "EVTOL.hpp"
#include <iostream>
#include <cassert>

// Shared test constants
const int testChargerCount1 = 2;
const int testChargerCount2 = 1;
const int testEVTOLId = 1;
const VehicleType testVehicleType = VehicleType::Alpha;
const VehicleProfile testProfile1 = {100, 100, 1.0, 0.5, 2, 0.01};
const VehicleProfile testProfile2 = {100, 50, 1.0, 0.5, 2, 0.01};
const int testChargerIndex = 0;
const int updateCycles = 10;

// Test assigning a charger to an EVTOL and verifying update is accepted
bool testAssignCharger() {
    ChargerManager cm(testChargerCount1);
    EVTOL e(testEVTOLId, testVehicleType, testProfile1);
    cm.assignCharger(e, testChargerIndex);
    cm.update(1);
    std::cout << "✅ testAssignCharger passed\n";
    return true;
}

// Test that the update cycle maintains charging state for an EVTOL
bool testUpdate() {
    ChargerManager cm(testChargerCount2);
    EVTOL e(testEVTOLId, testVehicleType, testProfile2);
    cm.assignCharger(e, testChargerIndex);
    for (int i = 0; i < updateCycles; ++i)
        cm.update(i);

    if (e.isCharging()) {
        std::cout << "✅ testUpdate passed\n";
        return true;
    } else {
        std::cerr << "❌ testUpdate failed: EVTOL is not charging when expected\n";
        return false;
    }
}

// Entry point for running all ChargerManager unit tests
int main() {
    int failed = 0;
    if (!testAssignCharger()) {
        std::cerr << "FAILED: testAssignCharger\n";
        ++failed;
    }
    if (!testUpdate()) {
        std::cerr << "FAILED: testUpdate\n";
        ++failed;
    }

    if (failed == 0) {
        std::cout << "✅ All ChargerManager tests passed\n";
        return 0;
    } else {
        std::cerr << "❌ " << failed << " ChargerManager test(s) failed\n";
        return 1;
    }
}
