#include "EchoEVTOL.hpp"

EchoEVTOL::EchoEVTOL(int id)
    : EVTOL(id, Config::VehicleType::Echo, Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Echo)]) {}

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
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Echo)].cruiseSpeed;
}

double EchoEVTOL::getBatteryCapacity() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Echo)].batteryCapacity;
}

double EchoEVTOL::getChargeTime() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Echo)].chargeTime;
}

double EchoEVTOL::getEnergyUsePerMile() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Echo)].energyUsePerMile;
}

int EchoEVTOL::getPassengerCount() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Echo)].passengerCount;
}

double EchoEVTOL::getFaultProbabilityPerHour() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Echo)].faultProbability;
}

const char* EchoEVTOL::getType() const {
    return "Echo";
}

void EchoEVTOL::injectFault() {
    faultActive = true;
}