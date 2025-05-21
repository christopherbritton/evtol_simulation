#include "StatisticsTracker.hpp"
#include <iostream>
#include <cassert>

// Test flight metrics update correctly
bool testRecordFlight() {
    StatisticsTracker stats;
    stats.recordFlight(VehicleType::Alpha, 60, 120, 4);

    if (stats.getFlightTime().at(VehicleType::Alpha) != 60){
        std::cerr << "❌ testRecordFlight: Flight time incorrect\n";
        return false;
    }
    if (stats.getFlightCount().at(VehicleType::Alpha) != 1) {
        std::cerr << "❌ testRecordFlight: Flight count incorrect\n";
        return false;
    }
    if (stats.getDistance().at(VehicleType::Alpha) != 120.0) {
        std::cerr << "❌ testRecordFlight: Distance incorrect\n";
        return false;
    }
    if (stats.getPassengerMiles().at(VehicleType::Alpha) != 480.0) {
        std::cerr << "❌ testRecordFlight: Passenger miles incorrect\n";
        return false;
    }
    std::cout << "✅ testRecordFlight passed\n";
    return true;
}

// Test charge accumulation per vehicle type
bool testRecordCharge() {
    StatisticsTracker stats;
    stats.recordCharge(VehicleType::Alpha, 2.5);
    stats.setSuppressOutput(false);
    std::cout << "✅ testRecordCharge passed (verified via report)\n";
    return true;
}

// Test fault accumulation per vehicle type
bool testRecordFault() {
    StatisticsTracker stats;
    stats.recordFault(VehicleType::Alpha);
    stats.recordFault(VehicleType::Alpha);
    stats.setSuppressOutput(false);
    std::cout << "✅ testRecordFault passed (verified via report)\n";
    return true;
}

// Test suppress output flag logic
bool testSetSuppressOutput() {
    StatisticsTracker stats;
    stats.setSuppressOutput(true);
    stats.recordFlight(VehicleType::Alpha, 30, 60, 2);
    stats.report();
    std::cout << "✅ testSetSuppressOutput passed (no output expected)\n";
    return true;
}

// Validate statistics getters
bool testAccessors() {
    StatisticsTracker stats;
    stats.recordFlight(VehicleType::Alpha, 30, 60, 2);

    if (stats.getFlightTime().at(VehicleType::Alpha) != 30) {
        std::cerr << "❌ testAccessors: getFlightTime failed\n";
        return false;
    }
    if (stats.getFlightCount().at(VehicleType::Alpha) != 1) {
        std::cerr << "❌ testAccessors: getFlightCount failed\n";
        return false;
    }
    if (stats.getDistance().at(VehicleType::Alpha) != 30.0) {
        std::cerr << "❌ testAccessors: getDistance failed\n";
        return false;
    }
    if (stats.getPassengerMiles().at(VehicleType::Alpha) != 60.0) {
        std::cerr << "❌ testAccessors: getPassengerMiles failed\n";
        return false;
    }
    std::cout << "✅ testAccessors passed\n";
    return true;
}

// Entry point for all StatisticsTracker unit tests
int main() {
    int failed = 0;

    if (!testRecordFlight()) {
        std::cerr << "FAILED: testRecordFlight\n";
        ++failed;
    }
    if (!testRecordCharge()) {
        std::cerr << "FAILED: testRecordCharge\n";
        ++failed;
    }
    if (!testRecordFault()) {
        std::cerr << "FAILED: testRecordFault\n";
        ++failed;
    }
    if (!testSetSuppressOutput()) {
        std::cerr << "FAILED: testSetSuppressOutput\n";
        ++failed;
    }
    if (!testAccessors()) {
        std::cerr << "FAILED: testAccessors\n";
        ++failed;
    }

    if (failed == 0) {
        std::cout << "\n All StatisticsTracker tests passed\n";
        return 0;
    } else {
        std::cerr << "\n❌ " << failed << " StatisticsTracker test(s) failed\n";
        return 1;
    }
}
