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
    return Config::DeltaSpec.cruiseSpeed;
}

double DeltaEVTOL::getBatteryCapacity() const {
    return Config::DeltaSpec.batteryCapacity;
}

double DeltaEVTOL::getChargeTime() const {
    return Config::DeltaSpec.chargeTime;
}

double DeltaEVTOL::getEnergyUsePerMile() const {
    return Config::DeltaSpec.energyUsePerMile;
}

int DeltaEVTOL::getPassengerCount() const {
    return Config::DeltaSpec.passengerCount;
}

double DeltaEVTOL::getFaultProbabilityPerHour() const {
    return Config::DeltaSpec.faultProbability;
}

const char* DeltaEVTOL::getType() const {
    return "Delta";
}

void DeltaEVTOL::injectFault() {
    faultActive = true;
}
