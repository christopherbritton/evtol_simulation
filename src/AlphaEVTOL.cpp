#include "AlphaEVTOL.hpp"

void AlphaEVTOL::fly(double hours) {
    double distance = spec.cruiseSpeed * hours;
    battery -= distance * spec.energyUsePerMile;
}

void AlphaEVTOL::charge() {
    battery = spec.batteryCapacity;
}

bool AlphaEVTOL::needsCharge() const {
    return battery <= 0;
}

double AlphaEVTOL::getCruiseSpeed() const { return spec.cruiseSpeed; }
double AlphaEVTOL::getBatteryCapacity() const { return spec.batteryCapacity; }
double AlphaEVTOL::getChargeTime() const { return spec.chargeTime; }
double AlphaEVTOL::getEnergyUsePerMile() const { return spec.energyUsePerMile; }
int AlphaEVTOL::getPassengerCount() const { return spec.passengerCount; }
double AlphaEVTOL::getFaultProbabilityPerHour() const { return spec.faultProbability; }
double AlphaEVTOL::getRemainingBattery() const { return battery; }
void AlphaEVTOL::resetBattery() { battery = spec.batteryCapacity; }
