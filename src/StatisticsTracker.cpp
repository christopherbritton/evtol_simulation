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
    // Retrieve EVTOL_MODE environment variable
    //std::cout << "[Debug] Entered report()!\n";


    const char* simEnv = std::getenv("EVTOL_MODE");
    std::string mode = simEnv ? simEnv : "NULL";
    bool isSimulationMode = (mode == "SIMULATION");
    //std::cout << "[Debug] EVTOL_MODE = " << mode << "\n";


    // Debug output to verify environment and suppression status
    //std::cout << "[Debug] suppressOutput=" << suppressOutput
    //          << ", isSimulationMode=" << isSimulationMode
    //          << ", EVTOL_MODE=" << mode << "\n";

    // Suppress output only if explicitly set or not in simulation mode
    if (!isSimulationMode && suppressOutput) return;

    // Normal statistics output
    std::cout << "\n-- Per-Vehicle-Type Statistics --\n";
    for (std::map<VehicleType, int>::const_iterator it = flightTime.begin(); it != flightTime.end(); ++it) {
        VehicleType type = it->first;
        int flights = flightCount[type];
        double avgTime = (flights > 0) ? (double)flightTime[type] / flights : 0;
        double avgDistance = (flights > 0) ? distance[type] / flights : 0;
        double avgCharge = (chargeCount[type] > 0) ? chargeTime[type] / chargeCount[type] : 0;

        std::cout << "  VehicleType " << static_cast<int>(type) << ":\n";
        std::cout << "    Avg Flight Time: " << avgTime << " mins\n";
        std::cout << "    Avg Distance per Flight: " << avgDistance << " miles\n";
        std::cout << "    Avg Charge Time: " << avgCharge << " hrs\n";
        std::cout << "    Total Faults: " << faultCount[type] << "\n";
        std::cout << "    Total Passenger Miles: " << passengerMiles[type] << "\n\n";
    }
}