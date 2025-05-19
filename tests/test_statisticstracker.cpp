
#include "StatisticsTracker.hpp"
#include "VehicleProfile.hpp"
#include "EVTOL.hpp"
#include <iostream>

// Unit test for StatisticsTracker
// Time Complexity: O(v), where v = number of EVTOLs
// Space Complexity: O(1), stats stored internally
int main() {
    VehicleProfile profile = {150, 100, 1, 0.5, 4, 0};
    std::vector<EVTOL> fleet;
    for (int i = 0; i < 5; ++i) {
        fleet.emplace_back(i + 1, VehicleType::Alpha, profile);
    }

    StatisticsTracker tracker;
    for (int t = 0; t < 10; ++t) {
        tracker.record(fleet);
    }

    std::cout << "StatisticsTracker test completed (check output below):\n";
    tracker.report();

    return 0;
}
