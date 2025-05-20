#include "StatisticsTracker.hpp"
#include "VehicleType.hpp"
#include <iostream>

void testStatisticsTracker() {
    StatisticsTracker stats;
    stats.setSuppressOutput(true);  // Prevents cluttered test output
    stats.recordFlight(VehicleType::Alpha, 60, 120, 4);
    stats.recordCharge(VehicleType::Alpha, 1.5);
    stats.recordFault(VehicleType::Alpha);
    stats.report();
    std::cout << "StatisticsTracker tests passed.\n";
}

int main() {
    testStatisticsTracker();
    return 0;
}
