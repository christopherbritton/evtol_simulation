#include "BravoEVTOL.hpp"
#include <algorithm>
#include <cstring>

void BravoEVTOL::fly(double hours) {
    double distance = cruiseSpeed * hours;                             // [miles]
    double energyUsed = distance * energyUsePerMile;                  // [kWh]
    batteryLevel -= energyUsed;
    charging = false;
}

void BravoEVTOL::charge() {
    batteryLevel = batteryCapacity;                                   // Full recharge
    charging = false;
}

bool BravoEVTOL::needsCharge() const {
    return batteryLevel < batteryCapacity * 0.25;                     // Needs charge if < 25%
}

double BravoEVTOL::getCruiseSpeed() const { return cruiseSpeed; }
double BravoEVTOL::getBatteryCapacity() const { return batteryCapacity; }
double BravoEVTOL::getChargeTime() const { return chargeTime; }
double BravoEVTOL::getEnergyUsePerMile() const { return energyUsePerMile; }
int BravoEVTOL::getPassengerCount() const { return passengerCount; }
double BravoEVTOL::getFaultProbabilityPerHour() const { return faultProbability; }

bool BravoEVTOL::isCharging() const { return charging; }
double BravoEVTOL::getChargeRate() const { return chargeRate; }
double BravoEVTOL::getBatteryLevel() const { return batteryLevel; }

void BravoEVTOL::charge(double hours) {
    batteryLevel += chargeRate * hours;
    if (batteryLevel >= batteryCapacity) {
        batteryLevel = batteryCapacity;
        charging = false;
    } else {
        charging = true;
    }
}

void BravoEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;
    charging = false;
}

int BravoEVTOL::getPassengerCapacity() const {
    return passengerCount;
}

const char* BravoEVTOL::getType() const {
    return "Bravo";
}

bool BravoEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability;
}

double BravoEVTOL::getRemainingBattery() const {
    return batteryLevel;
}