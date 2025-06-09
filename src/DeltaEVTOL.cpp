#include "DeltaEVTOL.hpp"

DeltaEVTOL::DeltaEVTOL() {
    batteryLevel = getBatteryCapacity();
}

void DeltaEVTOL::fly(double hours) {
    if (!faultActive && !isCharging()) {
        double energyUsed = hours * getCruiseSpeed() * getEnergyUsePerMile();
        batteryLevel -= energyUsed;
        if (batteryLevel < 0) batteryLevel = 0;
    }
}

void DeltaEVTOL::charge() {
    batteryLevel = getBatteryCapacity();
    charging = false;
}

bool DeltaEVTOL::needsCharge() const {
    return batteryLevel < getBatteryCapacity() * 0.25;
}

double DeltaEVTOL::getCruiseSpeed() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Delta)].cruiseSpeed;
}

double DeltaEVTOL::getBatteryCapacity() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Delta)].batteryCapacity;
}

double DeltaEVTOL::getChargeTime() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Delta)].chargeTime;
}

double DeltaEVTOL::getEnergyUsePerMile() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Delta)].energyUsePerMile;
}

int DeltaEVTOL::getPassengerCount() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Delta)].passengerCount;
}

double DeltaEVTOL::getFaultProbabilityPerHour() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Delta)].faultProbability;
}

const char* DeltaEVTOL::getType() const {
    return "Delta";
}

void DeltaEVTOL::injectFault() {
    faultActive = true;
}
