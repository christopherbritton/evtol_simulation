#include "EchoEVTOL.hpp"

EchoEVTOL::EchoEVTOL() {
    batteryLevel = getBatteryCapacity();
}

void EchoEVTOL::fly(double hours) {
    if (!faultActive && !isCharging()) {
        double energyUsed = hours * getCruiseSpeed() * getEnergyUsePerMile();
        batteryLevel -= energyUsed;
        if (batteryLevel < 0) batteryLevel = 0;
    }
}

void EchoEVTOL::charge() {
    batteryLevel = getBatteryCapacity();
    charging = false;
}

bool EchoEVTOL::needsCharge() const {
    return batteryLevel < getBatteryCapacity() * 0.25;
}

double EchoEVTOL::getCruiseSpeed() const {
    return Config::EchoSpec.cruiseSpeed;
}

double EchoEVTOL::getBatteryCapacity() const {
    return Config::EchoSpec.batteryCapacity;
}

double EchoEVTOL::getChargeTime() const {
    return Config::EchoSpec.chargeTime;
}

double EchoEVTOL::getEnergyUsePerMile() const {
    return Config::EchoSpec.energyUsePerMile;
}

int EchoEVTOL::getPassengerCount() const {
    return Config::EchoSpec.passengerCount;
}

double EchoEVTOL::getFaultProbabilityPerHour() const {
    return Config::EchoSpec.faultProbability;
}

const char* EchoEVTOL::getType() const {
    return "Echo";
}

void EchoEVTOL::injectFault() {
    faultActive = true;
}