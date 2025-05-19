#pragma once
#include <string>

struct VehicleType {
    std::string name;
    double cruiseSpeed;
    double batteryCapacity;
    double chargeTime;
    double energyUse;
    int passengers;
    double faultProb;
};