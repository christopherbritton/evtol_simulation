#pragma once

#include "VehicleType.hpp"
#include <map>

class StatisticsTracker {
public:
    void recordFlight(VehicleType type, int durationMinutes, double speed, int passengers);
    void recordCharge(VehicleType type, double durationHours);
    void recordFault(VehicleType type);
    void report();
    void setSuppressOutput(bool suppress);

private:
    std::map<VehicleType, int> flightTime;
    std::map<VehicleType, int> flightCount;
    std::map<VehicleType, double> distance;
    std::map<VehicleType, double> chargeTime;
    std::map<VehicleType, int> chargeCount;
    std::map<VehicleType, int> faultCount;
    std::map<VehicleType, double> passengerMiles;
    bool suppressOutput = false;
};

