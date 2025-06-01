#include "DeltaEVTOL.hpp"

void DeltaEVTOL::fly(double hours) {
    double distance = spec.cruiseSpeed * hours;
    battery -= distance * spec.energyUsePerMile;
}

void DeltaEVTOL::charge() {
    battery = spec.batteryCapacity;
}

bool DeltaEVTOL::needsCharge() const {
    return battery <= 0;
}

double DeltaEVTOL::getCruiseSpeed() const { return spec.cruiseSpeed; }
double DeltaEVTOL::getBatteryCapacity() const { return spec.batteryCapacity; }
double DeltaEVTOL::getChargeTime() const { return spec.chargeTime; }
double DeltaEVTOL::getEnergyUsePerMile() const { return spec.energyUsePerMile; }
int DeltaEVTOL::getPassengerCount() const { return spec.passengerCount; }
double DeltaEVTOL::getFaultProbabilityPerHour() const { return spec.faultProbability; }
double DeltaEVTOL::getRemainingBattery() const { return battery; }
void DeltaEVTOL::resetBattery() { battery = spec.batteryCapacity; }
