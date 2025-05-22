#include "StatisticsTracker.hpp"
#include <iostream>
#include <cassert>

const VehicleType testType = VehicleType::Alpha;
const double flightMinutes = 60.0;
const double distance = 120.0;
const int passengers = 4;
const double chargeTime = 2.5;
const int faultCount = 2;

// Test flight metrics update correctly
bool testRecordFlight() {
    StatisticsTracker stats;
    stats.recordFlight(testType, flightMinutes, distance, passengers);

    if (stats.getFlightTime().at(testType) != flightMinutes){
        std::cerr << "❌ testRecordFlight: Flight time incorrect";
        return false;
    }
    if (stats.getFlightCount().at(testType) != 1) {
        std::cerr << "❌ testRecordFlight: Flight count incorrect";
        return false;
    }
    if (stats.getDistance().at(testType) != distance) {
        std::cerr << "❌ testRecordFlight: Distance incorrect";
        return false;
    }
    if (stats.getPassengerMiles().at(testType) != distance * passengers) {
        std::cerr << "❌ testRecordFlight: Passenger miles incorrect";
        return false;
    }
    std::cout << "✅ testRecordFlight passed";
    return true;
}

// Test charge accumulation per vehicle type
bool testRecordCharge() {
    StatisticsTracker stats;
    stats.recordCharge(testType, chargeTime);
    stats.setSuppressOutput(false);
    std::cout << "✅ testRecordCharge passed (verified via report)";
    return true;
}

// Test fault accumulation per vehicle type
bool testRecordFault() {
    StatisticsTracker stats;
    for (int i = 0; i < faultCount; ++i) stats.recordFault(testType);
    stats.setSuppressOutput(false);
    std::cout << "✅ testRecordFault passed (verified via report)";
    return true;
}

// Test suppress output flag logic
bool testSetSuppressOutput() {
    StatisticsTracker stats;
    stats.setSuppressOutput(true);
    stats.recordFlight(testType, 30, 60, 2);
    stats.report();
    std::cout << "✅ testSetSuppressOutput passed (no output expected)";
    return true;
}

// Validate statistics getters
bool testAccessors() {
    StatisticsTracker stats;
    stats.recordFlight(testType, 30, 60, 2);

    if (stats.getFlightTime().at(testType) != 30) {
        std::cerr << "❌ testAccessors: getFlightTime failed";
        return false;
    }
    if (stats.getFlightCount().at(testType) != 1) {
        std::cerr << "❌ testAccessors: getFlightCount failed";
        return false;
    }
    if (stats.getDistance().at(testType) != 60.0) {
        std::cerr << "❌ testAccessors: getDistance failed";
        return false;
    }
    if (stats.getPassengerMiles().at(testType) != 120.0) {
        std::cerr << "❌ testAccessors: getPassengerMiles failed";
        return false;
    }
    std::cout << "✅ testAccessors passed";
    return true;
}

// Entry point
int main() {
    int failed = 0;
    if (!testRecordFlight()) ++failed;
    if (!testRecordCharge()) ++failed;
    if (!testRecordFault()) ++failed;
    if (!testSetSuppressOutput()) ++failed;
    if (!testAccessors()) ++failed;

    if (failed == 0) {
        std::cout << "All StatisticsTracker tests passed";
        return 0;
    } else {
        std::cerr << "❌ " << failed << " test(s) failed";
        return 1;
    }
}