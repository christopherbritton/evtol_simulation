#include "AlphaEVTOL.hpp"
#include <algorithm>
#include <cstring>

void AlphaEVTOL::fly(double hours) {
    double miles = cruiseSpeed * hours;
    double energyUsed = miles * energyUsePerMile;
    batteryLevel = std::max(0.0, batteryLevel - energyUsed);
    charging = false;
}

void AlphaEVTOL::charge() {
    charging = true;
}

bool AlphaEVTOL::needsCharge() const {
    return batteryLevel < (batteryCapacity * 0.1);
}

double AlphaEVTOL::getCruiseSpeed() const {
    return cruiseSpeed;
}

double AlphaEVTOL::getBatteryCapacity() const {
    return batteryCapacity;
}

double AlphaEVTOL::getChargeTime() const {
    return chargeTime;
}

double AlphaEVTOL::getEnergyUsePerMile() const {
    return energyUsePerMile;
}

int AlphaEVTOL::getPassengerCount() const {
    return passengerCount;
}

double AlphaEVTOL::getFaultProbabilityPerHour() const {
    return faultProbability;
}

bool AlphaEVTOL::isCharging() const {
    return charging;
}

double AlphaEVTOL::getChargeRate() const {
    return chargeRate;
}

double AlphaEVTOL::getBatteryLevel() const {
    return batteryLevel;
}

void AlphaEVTOL::charge(double hours) {
    if (charging) {
        batteryLevel = std::min(batteryCapacity, batteryLevel + chargeRate * hours);
    }
}

void AlphaEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;
    charging = false;
}

int AlphaEVTOL::getPassengerCapacity() const {
    return passengerCount;
}

const char* AlphaEVTOL::getType() const {
    return "Alpha";
}

bool AlphaEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability;
}

double AlphaEVTOL::getRemainingBattery() const {
    return batteryLevel;
}