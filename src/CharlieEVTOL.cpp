#include "CharlieEVTOL.hpp"
#include <algorithm>
#include <cstring>

void CharlieEVTOL::fly(double hours) {
    double distance = cruiseSpeed * hours;                             // [miles]
    double energyUsed = distance * energyUsePerMile;                  // [kWh]
    batteryLevel -= energyUsed;
    charging = false;
}

void CharlieEVTOL::charge() {
    batteryLevel = batteryCapacity;                                   // Full recharge
    charging = false;
}

bool CharlieEVTOL::needsCharge() const {
    return batteryLevel < batteryCapacity * 0.25;                     // Needs charge if < 25%
}

double CharlieEVTOL::getCruiseSpeed() const { return cruiseSpeed; }
double CharlieEVTOL::getBatteryCapacity() const { return batteryCapacity; }
double CharlieEVTOL::getChargeTime() const { return chargeTime; }
double CharlieEVTOL::getEnergyUsePerMile() const { return energyUsePerMile; }
int CharlieEVTOL::getPassengerCount() const { return passengerCount; }
double CharlieEVTOL::getFaultProbabilityPerHour() const { return faultProbability; }

bool CharlieEVTOL::isCharging() const { return charging; }
double CharlieEVTOL::getChargeRate() const { return chargeRate; }
double CharlieEVTOL::getBatteryLevel() const { return batteryLevel; }

void CharlieEVTOL::charge(double hours) {
    batteryLevel += chargeRate * hours;
    if (batteryLevel >= batteryCapacity) {
        batteryLevel = batteryCapacity;
        charging = false;
    } else {
        charging = true;
    }
}

void CharlieEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;
    charging = false;
}

int CharlieEVTOL::getPassengerCapacity() const {
    return passengerCount;
}

const char* CharlieEVTOL::getType() const {
    return "Charlie";
} 

bool CharlieEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability;
}

double CharlieEVTOL::getRemainingBattery() const {
    return batteryLevel;
}