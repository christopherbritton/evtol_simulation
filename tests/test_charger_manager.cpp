#include "ChargerManager.hpp"
#include "EVTOL.hpp"
#include <iostream>
#include <cassert>

// Test assigning a charger to an EVTOL and verifying update is accepted
bool testAssignCharger() {
    ChargerManager cm(2);
    VehicleProfile profile = {100, 100, 1.0, 0.5, 2, 0.01};
    EVTOL e(1, VehicleType::Alpha, profile);
    cm.assignCharger(e, 0);
    cm.update(1);
    std::cout << "✅ testAssignCharger passed\n";
    return true;
}

// Test that the update cycle maintains charging state for an EVTOL
bool testUpdate() {
    ChargerManager cm(1);
    VehicleProfile profile = {100, 50, 1.0, 0.5, 2, 0.01};
    EVTOL e(1, VehicleType::Alpha, profile);
    cm.assignCharger(e, 0);
    for (int i = 0; i < 10; ++i) cm.update(i);

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
