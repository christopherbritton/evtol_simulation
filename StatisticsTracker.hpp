#pragma once
#include "EVTOL.hpp"
#include <vector>
// Collects and reports simulation stats
class StatisticsTracker {
public:
    void record(const std::vector<EVTOL>& evtols);  // Time: O(n), Space: O(1)
    void report() const;                            // Time: O(1), Space: O(1)
private:
    int totalSteps = 0;
    int totalFaults = 0;
    int totalChargingRequests = 0;
};
