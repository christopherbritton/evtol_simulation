#include "BravoEVTOL.hpp"

// Constructor initializes battery to full
BravoEVTOL::BravoEVTOL() {
    batteryLevel = getBatteryCapacity();
}

void BravoEVTOL::fly(double hours) {
    if (!faultActive && !isCharging()) {
        double energyUsed = hours * getCruiseSpeed() * getEnergyUsePerMile();
        batteryLevel -= energyUsed;
        if (batteryLevel < 0) batteryLevel = 0;
    }
}

void BravoEVTOL::charge() {
    batteryLevel = getBatteryCapacity();
    charging = false;
}

bool BravoEVTOL::needsCharge() const {
    return batteryLevel < getBatteryCapacity() * 0.25;
}

double BravoEVTOL::getCruiseSpeed() const {
    return Config::BravoSpec.cruiseSpeed;
}

double BravoEVTOL::getBatteryCapacity() const {
    return Config::BravoSpec.batteryCapacity;
}

double BravoEVTOL::getChargeTime() const {
    return Config::BravoSpec.chargeTime;
}

double BravoEVTOL::getEnergyUsePerMile() const {
    return Config::BravoSpec.energyUsePerMile;
}

int BravoEVTOL::getPassengerCount() const {
    return Config::BravoSpec.passengerCount;
}

double BravoEVTOL::getFaultProbabilityPerHour() const {
    return Config::BravoSpec.faultProbability;
}

const char* BravoEVTOL::getType() const {
    return "Bravo";
}

void BravoEVTOL::injectFault() {
    faultActive = true;
}
