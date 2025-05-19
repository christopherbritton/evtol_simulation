
#include "StatisticsTracker.hpp"
#include <iostream>

// Time Complexity: O(n), where n = number of EVTOLs
// Space Complexity: O(1), incremental updates to maps
void StatisticsTracker::record(const std::vector<EVTOL>& evtols) {
    ++totalSteps;
    for (size_t i = 0; i < evtols.size(); ++i) {
        const EVTOL& e = evtols[i];
        if (!e.needsCharging()) {
            totalMiles[e.getType()] += 1.0;  // Simulate mileage accumulation
        }
        flightSessions[e.getType()] += 1;
    }
}

// Time Complexity: O(m), where m = number of vehicle types tracked
// Space Complexity: O(1), only reads from stored maps
void StatisticsTracker::report() const {
    std::cout << "\n--- Simulation Summary ---\n";
    std::map<VehicleType, double>::const_iterator it = totalMiles.begin();
    while (it != totalMiles.end()) {
        VehicleType type = it->first;
        double miles = it->second;
        int sessions = flightSessions.at(type);
        std::cout << "VehicleType " << static_cast<int>(type)
                  << ": Miles = " << miles
                  << ", Sessions = " << sessions << "\n";
        ++it;
    }
}
