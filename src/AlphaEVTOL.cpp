// AlphaEVTOL.cpp - Implementation of the Alpha EVTOL derived class
#include "AlphaEVTOL.hpp"

AlphaEVTOL::AlphaEVTOL(int id)
    : EVTOL(id, Config::VehicleType::Alpha, Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Alpha)]) {}

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
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Alpha)].cruiseSpeed;
}

double AlphaEVTOL::getBatteryCapacity() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Alpha)].batteryCapacity;
}

double AlphaEVTOL::getChargeTime() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Alpha)].chargeTime;
}

double AlphaEVTOL::getEnergyUsePerMile() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Alpha)].energyUsePerMile;
}

int AlphaEVTOL::getPassengerCount() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Alpha)].passengerCount;
}

double AlphaEVTOL::getFaultProbabilityPerHour() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Alpha)].faultProbability;
}

const char* AlphaEVTOL::getType() const {
    return "Alpha";
}

void AlphaEVTOL::injectFault() {
    faultActive = true;
}