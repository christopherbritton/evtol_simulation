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

    const std::map<VehicleType, int>& getFlightTime() const { return flightTime; }
    const std::map<VehicleType, int>& getFlightCount() const { return flightCount; }
    const std::map<VehicleType, double>& getDistance() const { return distance; }
    const std::map<VehicleType, double>& getChargeTime() const { return chargeTime; }
    const std::map<VehicleType, int>& getFaultCount() const { return faultCount; }
    const std::map<VehicleType, double>& getPassengerMiles() const { return passengerMiles; }


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

