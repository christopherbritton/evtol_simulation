#include "BravoEVTOL.hpp"

// Constructor initializes battery to full
BravoEVTOL::BravoEVTOL(int id)
    : EVTOL(id, Config::VehicleType::Bravo, Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Bravo)]) {}

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
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Bravo)].cruiseSpeed;
}

double BravoEVTOL::getBatteryCapacity() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Bravo)].batteryCapacity;
}

double BravoEVTOL::getChargeTime() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Bravo)].chargeTime;
}

double BravoEVTOL::getEnergyUsePerMile() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Bravo)].energyUsePerMile;
}

int BravoEVTOL::getPassengerCount() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Bravo)].passengerCount;
}

double BravoEVTOL::getFaultProbabilityPerHour() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Bravo)].faultProbability;
}

const char* BravoEVTOL::getType() const {
    return "Bravo";
}

void BravoEVTOL::injectFault() {
    faultActive = true;
}
