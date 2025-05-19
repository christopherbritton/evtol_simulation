#include "StatisticsTracker.hpp"
#include <iostream>
void StatisticsTracker::record(const std::vector<EVTOL>& evtols) {
    ++totalSteps;
    for (size_t i = 0; i < evtols.size(); ++i) {
        if (evtols[i].hasFault()) ++totalFaults;
        if (evtols[i].needsCharging()) ++totalChargingRequests;
    }
}
void StatisticsTracker::report() const {
    std::cout << "Simulation Statistics:\n";
    std::cout << "Total Steps: " << totalSteps << "\n";
    std::cout << "Total Faults: " << totalFaults << "\n";
    std::cout << "Total Charging Requests: " << totalChargingRequests << "\n";
}
