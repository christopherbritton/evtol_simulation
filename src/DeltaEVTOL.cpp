#include "DeltaEVTOL.hpp"
#include <algorithm>
#include <cstring>

void DeltaEVTOL::fly(double hours) {
    double energyUsed = hours * cruiseSpeed * energyUsePerMile;
    batteryLevel = std::max(0.0, batteryLevel - energyUsed);
    charging = false;
}

void DeltaEVTOL::charge() {
    batteryLevel = batteryCapacity;
    charging = false;
}

bool DeltaEVTOL::needsCharge() const {
    return batteryLevel < (0.2 * batteryCapacity);
}

double DeltaEVTOL::getCruiseSpeed() const {
    return cruiseSpeed;
}

double DeltaEVTOL::getBatteryCapacity() const {
    return batteryCapacity;
}

double DeltaEVTOL::getChargeTime() const {
    return chargeTime;
}

double DeltaEVTOL::getEnergyUsePerMile() const {
    return energyUsePerMile;
}

int DeltaEVTOL::getPassengerCount() const {
    return passengerCount;
}

double DeltaEVTOL::getFaultProbabilityPerHour() const {
    return faultProbability;
}

bool DeltaEVTOL::isCharging() const {
    return charging;
}

double DeltaEVTOL::getChargeRate() const {
    return chargeRate;
}

double DeltaEVTOL::getBatteryLevel() const {
    return batteryLevel;
}

void DeltaEVTOL::charge(double hours) {
    batteryLevel = std::min(batteryCapacity, batteryLevel + hours * chargeRate);
    charging = true;
}

void DeltaEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;
    charging = false;
}

int DeltaEVTOL::getPassengerCapacity() const {
    return passengerCount;
}

const char* DeltaEVTOL::getType() const {
    return "Delta";
}

bool DeltaEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability;
}

double DeltaEVTOL::getRemainingBattery() const {
    return batteryLevel;
}
