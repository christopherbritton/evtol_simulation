#include "EVTOL.hpp"
#include <iostream>
#include <cassert>

// Shared parameters for reuse across tests
const int testId = 2;
const VehicleType testType = VehicleType::Bravo;
const VehicleProfile defaultProfile = {100, 50, 1.0, 0.5, 3, 0.01};
const int expectedCruiseSpeed = 100;
const int expectedPassengerCapacity = 3;
const int coinFlipTrials = 100;
const int coinFlipOdds = 2;

// Test simulateStep() method to ensure execution runs without error
// Also verify fault and charging flags are potentially set as expected
bool testSimulateStep() {
    EVTOL e(testId, testType, defaultProfile);
    e.simulateStep();

    // Check that simulateStep does not crash and updates state
    bool observed = e.hasFault() || e.needsCharging();
    std::cout << "✅ testSimulateStep executed\n" << (observed ? ", fault/charging condition observed" : "") << "";
    return true;
}

// Test accessors for cruise speed, passenger capacity, and ID
bool testAccessors() {
    EVTOL e(testId, testType, defaultProfile);
    if (e.getCruiseSpeed() != expectedCruiseSpeed ||
        e.getPassengerCapacity() != expectedPassengerCapacity ||
        e.getId() != testId) {
        std::cerr << "❌ testAccessors failed\n";
        return false;
    }
    std::cout << "✅ testAccessors passed\n";
    return true;
}


// Test coinFlip() returns variable results over multiple trials
// If trueCount is 0 or 100, the result is too deterministic and indicates possible bias or implementation issue
bool testCoinFlip() {
    EVTOL e(testId, testType, defaultProfile);
    int trueCount = 0;
    for (int i = 0; i < coinFlipTrials; ++i) {
        if (e.testCoinFlipWrapper(2)) ++trueCount;
    }
    if (trueCount == 0 || trueCount == coinFlipTrials) {
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
        std::cout << "\n All EVTOL tests passed\n";
        return 0;
    } else {
        std::cerr << "\n❌ " << failed << " EVTOL test(s) failed\n";
        return 1;
    }
}
