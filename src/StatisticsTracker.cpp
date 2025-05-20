#include "StatisticsTracker.hpp"
#include <iostream>
#include <unistd.h> // For isatty and STDOUT_FILENO

void StatisticsTracker::recordFlight(VehicleType type, int durationMinutes, double speed, int passengers) {
    flightTime[type] += durationMinutes;
    flightCount[type]++;
    distance[type] += (speed * durationMinutes / 60.0);
    passengerMiles[type] += (speed * durationMinutes / 60.0) * passengers;
}

void StatisticsTracker::recordCharge(VehicleType type, double durationHours) {
    chargeTime[type] += durationHours;
    chargeCount[type]++;
}

void StatisticsTracker::recordFault(VehicleType type) {
    faultCount[type]++;
}

void StatisticsTracker::setSuppressOutput(bool suppress) {
    suppressOutput = suppress;
}

void StatisticsTracker::report() {
    // Suppress output if flagged, or if running in non-interactive (test) mode
    if (suppressOutput || !isatty(STDOUT_FILENO)) return;

    std::cout << "\n-- Per-Vehicle-Type Statistics --\n";
    for (const auto& pair : flightTime) {
        VehicleType type = pair.first;
        int flights = flightCount[type];
        double avgTime = (flights > 0) ? (double)flightTime[type] / flights : 0;
        double avgDistance = (flights > 0) ? distance[type] / flights : 0;
        double avgCharge = (chargeCount[type] > 0) ? chargeTime[type] / chargeCount[type] : 0;

        std::cout << "VehicleType " << static_cast<int>(type) << ":\n";
        std::cout << "  Avg Flight Time: " << avgTime << " mins\n";
        std::cout << "  Avg Distance per Flight: " << avgDistance << " miles\n";
        std::cout << "  Avg Charge Time: " << avgCharge << " hrs\n";
        std::cout << "  Total Faults: " << faultCount[type] << "\n";
        std::cout << "  Total Passenger Miles: " << passengerMiles[type] << "\n\n";
    }
}