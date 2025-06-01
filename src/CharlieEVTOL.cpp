#include "CharlieEVTOL.hpp"

void CharlieEVTOL::fly(double hours) {
    double distance = spec.cruiseSpeed * hours;
    battery -= distance * spec.energyUsePerMile;
}

void CharlieEVTOL::charge() {
    battery = spec.batteryCapacity;
}

bool CharlieEVTOL::needsCharge() const {
    return battery <= 0;
}

double CharlieEVTOL::getCruiseSpeed() const { return spec.cruiseSpeed; }
double CharlieEVTOL::getBatteryCapacity() const { return spec.batteryCapacity; }
double CharlieEVTOL::getChargeTime() const { return spec.chargeTime; }
double CharlieEVTOL::getEnergyUsePerMile() const { return spec.energyUsePerMile; }
int CharlieEVTOL::getPassengerCount() const { return spec.passengerCount; }
double CharlieEVTOL::getFaultProbabilityPerHour() const { return spec.faultProbability; }
double CharlieEVTOL::getRemainingBattery() const { return battery; }
void CharlieEVTOL::resetBattery() { battery = spec.batteryCapacity; }
