#include "BravoEVTOL.hpp"

void BravoEVTOL::fly(double hours) {
    double distance = spec.cruiseSpeed * hours;
    battery -= distance * spec.energyUsePerMile;
}

void BravoEVTOL::charge() {
    battery = spec.batteryCapacity;
}

bool BravoEVTOL::needsCharge() const {
    return battery <= 0;
}

double BravoEVTOL::getCruiseSpeed() const { return spec.cruiseSpeed; }
double BravoEVTOL::getBatteryCapacity() const { return spec.batteryCapacity; }
double BravoEVTOL::getChargeTime() const { return spec.chargeTime; }
double BravoEVTOL::getEnergyUsePerMile() const { return spec.energyUsePerMile; }
int BravoEVTOL::getPassengerCount() const { return spec.passengerCount; }
double BravoEVTOL::getFaultProbabilityPerHour() const { return spec.faultProbability; }
double BravoEVTOL::getRemainingBattery() const { return battery; }
void BravoEVTOL::resetBattery() { battery = spec.batteryCapacity; }
