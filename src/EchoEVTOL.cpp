#include "EchoEVTOL.hpp"
#include <algorithm>
#include <cstring>

void EchoEVTOL::fly(double hours) {
    double miles = cruiseSpeed * hours;
    double energyUsed = miles * energyUsePerMile;
    batteryLevel = std::max(0.0, batteryLevel - energyUsed);
    charging = false;
}

void EchoEVTOL::charge() {
    charging = true;
}

bool EchoEVTOL::needsCharge() const {
    return batteryLevel < (batteryCapacity * 0.1);
}

double EchoEVTOL::getCruiseSpeed() const {
    return cruiseSpeed;
}

double EchoEVTOL::getBatteryCapacity() const {
    return batteryCapacity;
}

double EchoEVTOL::getChargeTime() const {
    return chargeTime;
}

double EchoEVTOL::getEnergyUsePerMile() const {
    return energyUsePerMile;
}

int EchoEVTOL::getPassengerCount() const {
    return passengerCount;
}

double EchoEVTOL::getFaultProbabilityPerHour() const {
    return faultProbability;
}

bool EchoEVTOL::isCharging() const {
    return charging;
}

double EchoEVTOL::getChargeRate() const {
    return chargeRate;
}

double EchoEVTOL::getBatteryLevel() const {
    return batteryLevel;
}

void EchoEVTOL::charge(double hours) {
    if (charging) {
        batteryLevel = std::min(batteryCapacity, batteryLevel + chargeRate * hours);
    }
}

void EchoEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;
    charging = false;
}

int EchoEVTOL::getPassengerCapacity() const {
    return passengerCount;
}

const char* EchoEVTOL::getType() const {
    return "Echo";
}

bool EchoEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability;
}

double EchoEVTOL::getRemainingBattery() const {
    return batteryLevel;
}