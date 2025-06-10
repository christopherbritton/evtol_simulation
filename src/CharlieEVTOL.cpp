#include "CharlieEVTOL.hpp"

CharlieEVTOL::CharlieEVTOL(int id)
    : EVTOL(id, Config::VehicleType::Charlie, Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Charlie)]) {}

void CharlieEVTOL::fly(double hours) {
    if (!isCharging()) {
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
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Charlie)].cruiseSpeed;
}

double CharlieEVTOL::getBatteryCapacity() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Charlie)].batteryCapacity;
}

double CharlieEVTOL::getChargeTime() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Charlie)].chargeTime;
}

double CharlieEVTOL::getEnergyUsePerMile() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Charlie)].energyUsePerMile;
}

int CharlieEVTOL::getPassengerCount() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Charlie)].passengerCount;
}

double CharlieEVTOL::getFaultProbabilityPerHour() const {
    return Config::VehicleSpecs[static_cast<int>(Config::VehicleType::Charlie)].faultProbability;
}

const char* CharlieEVTOL::getType() const {
    return "Charlie";
}

void CharlieEVTOL::injectFault() {
    faultActive = true;
}
