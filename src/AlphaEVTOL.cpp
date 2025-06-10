// AlphaEVTOL.cpp - Implementation of the Alpha EVTOL derived class
#include "AlphaEVTOL.hpp"

// Constructor initializes AlphaEVTOL with its unique ID and AlphaSpec
AlphaEVTOL::AlphaEVTOL(int id)
    : EVTOL(id, Config::VehicleType::Alpha, Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Alpha)]) {}

void AlphaEVTOL::fly(double hours) {
    if (!isCharging()) {            //Could add conditional logic if fault is severe enough to discontinue flight
        double energyUsed = hours * getCruiseSpeed() * getEnergyUsePerMile();
        batteryLevel -= energyUsed;
        if (batteryLevel < 0) batteryLevel = 0;
    }
}

// Fully recharges the battery and exits charging state
void AlphaEVTOL::charge() {
    batteryLevel = getBatteryCapacity();
    charging = false;
}

// Returns true if battery level falls below 25% capacity
bool AlphaEVTOL::needsCharge() const {
    return batteryLevel < getBatteryCapacity() * 0.25;
}

// Accessors pulling from Alpha vehicle specification

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

// Returns string identifier of the vehicle type
const char* AlphaEVTOL::getType() const {
    return "Alpha";
}

// Activates fault flag for this vehicle
void AlphaEVTOL::injectFault() {
    faultActive = true;
}