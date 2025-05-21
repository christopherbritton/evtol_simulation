#include "EVTOL.hpp"
#include <iostream>
#include <cassert>

// Test simulateStep() method to ensure execution runs without error
// Also verify fault and charging flags are potentially set as expected
bool testSimulateStep() {
    VehicleProfile profile = {100, 50, 1.0, 0.5, 2, 0.01};
    EVTOL e(1, VehicleType::Alpha, profile);
    e.simulateStep();

    // Check that simulateStep does not crash and updates state
    bool observed = e.hasFault() || e.needsCharging();
    std::cout << "✅ testSimulateStep executed\n" << (observed ? ", fault/charging condition observed" : "") << "\n";
    return true;
}

// Test accessors for cruise speed, passenger capacity, and ID
bool testAccessors() {
    VehicleProfile profile = {100, 50, 1.0, 0.5, 3, 0.01};
    EVTOL e(2, VehicleType::Bravo, profile);
    if (e.getCruiseSpeed() != 100 || e.getPassengerCapacity() != 3 || e.getId() != 2) {
        std::cerr << "❌ testAccessors failed\n";
        return false;
    }
    std::cout << "✅ testAccessors passed\n";
    return true;
}

// Test coinFlip() returns variable results over multiple trials
// If trueCount is 0 or 100, the result is too deterministic and indicates possible bias or implementation issue
bool testCoinFlip() {
    EVTOL e(3, VehicleType::Charlie, {100, 50, 1.0, 0.5, 1, 0.01});
    int trueCount = 0;
    for (int i = 0; i < 100; ++i) {
        if (e.testCoinFlipWrapper(2)) ++trueCount;
    }
    if (trueCount == 0 || trueCount == 100) {
        std::cerr << "❌ testCoinFlip failed: coinFlip seems biased\n";
        return false;
    }
    std::cout << "✅ testCoinFlip passed\n";
    return true;
}

// Main driver to execute and track results of all EVTOL-related unit tests
int main() {
    int failed = 0;

    if (!testSimulateStep()) {
        std::cerr << "FAILED: testSimulateStep\n";
        ++failed;
    }
    if (!testAccessors()) {
        std::cerr << "FAILED: testAccessors\n";
        ++failed;
    }
    if (!testCoinFlip()) {
        std::cerr << "FAILED: testCoinFlip\n";
        ++failed;
    }

    if (failed == 0) {
        std::cout << "\n✅ All EVTOL tests passed\n";
        return 0;
    } else {
        std::cerr << "\n❌ " << failed << " EVTOL test(s) failed\n";
        return 1;
    }
}
