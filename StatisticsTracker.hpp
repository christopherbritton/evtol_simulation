
#pragma once
#include "EVTOL.hpp"
#include "VehicleType.hpp"
#include <vector>
#include <map>

// Tracks simulation statistics by vehicle type
class StatisticsTracker {
public:
    void record(const std::vector<EVTOL>& evtols); // Collect data each time step
    void report() const;                           // Output aggregated statistics

private:
    int totalSteps = 0;
    std::map<VehicleType, double> totalMiles;      // Cumulative miles per type
    std::map<VehicleType, int> flightSessions;     // Number of updates recorded per type
};
