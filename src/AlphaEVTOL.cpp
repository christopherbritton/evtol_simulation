#include "AlphaEVTOL.hpp"

AlphaEVTOL::AlphaEVTOL() {
    batteryLevel = getBatteryCapacity();
}

void AlphaEVTOL::fly(double hours) {
    if (!faultActive && !isCharging()) {
        double energyUsed = hours * getCruiseSpeed() * getEnergyUsePerMile();
        batteryLevel -= energyUsed;
        if (batteryLevel < 0) batteryLevel = 0;
    }
}

void AlphaEVTOL::charge() {
    batteryLevel = getBatteryCapacity();
    charging = false;
}

bool AlphaEVTOL::needsCharge() const {
    return batteryLevel < getBatteryCapacity() * 0.25;
}

double AlphaEVTOL::getCruiseSpeed() const {
    return Config::AlphaSpec.cruiseSpeed;
}

double AlphaEVTOL::getBatteryCapacity() const {
    return Config::AlphaSpec.batteryCapacity;
}

double AlphaEVTOL::getChargeTime() const {
    return Config::AlphaSpec.chargeTime;
}

double AlphaEVTOL::getEnergyUsePerMile() const {
    return Config::AlphaSpec.energyUsePerMile;
}

int AlphaEVTOL::getPassengerCount() const {
    return Config::AlphaSpec.passengerCount;
}

double AlphaEVTOL::getFaultProbabilityPerHour() const {
    return Config::AlphaSpec.faultProbability;
}

const char* AlphaEVTOL::getType() const {
    return "Alpha";
}

void AlphaEVTOL::injectFault() {
    faultActive = true;
}