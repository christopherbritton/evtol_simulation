#include "CharlieEVTOL.hpp"

CharlieEVTOL::CharlieEVTOL() {
    batteryLevel = getBatteryCapacity();
}

void CharlieEVTOL::fly(double hours) {
    if (!faultActive && !isCharging()) {
        double energyUsed = hours * getCruiseSpeed() * getEnergyUsePerMile();
        batteryLevel -= energyUsed;
        if (batteryLevel < 0) batteryLevel = 0;
    }
}

void CharlieEVTOL::charge() {
    batteryLevel = getBatteryCapacity();
    charging = false;
}

bool CharlieEVTOL::needsCharge() const {
    return batteryLevel < getBatteryCapacity() * 0.25;
}

double CharlieEVTOL::getCruiseSpeed() const {
    return Config::CharlieSpec.cruiseSpeed;
}

double CharlieEVTOL::getBatteryCapacity() const {
    return Config::CharlieSpec.batteryCapacity;
}

double CharlieEVTOL::getChargeTime() const {
    return Config::CharlieSpec.chargeTime;
}

double CharlieEVTOL::getEnergyUsePerMile() const {
    return Config::CharlieSpec.energyUsePerMile;
}

int CharlieEVTOL::getPassengerCount() const {
    return Config::CharlieSpec.passengerCount;
}

double CharlieEVTOL::getFaultProbabilityPerHour() const {
    return Config::CharlieSpec.faultProbability;
}

const char* CharlieEVTOL::getType() const {
    return "Charlie";
}

void CharlieEVTOL::injectFault() {
    faultActive = true;
}
