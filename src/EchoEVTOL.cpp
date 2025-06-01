#include "EchoEVTOL.hpp"

void EchoEVTOL::fly(double hours) {
    double distance = spec.cruiseSpeed * hours;
    battery -= distance * spec.energyUsePerMile;
}

void EchoEVTOL::charge() {
    battery = spec.batteryCapacity;
}

bool EchoEVTOL::needsCharge() const {
    return battery <= 0;
}

double EchoEVTOL::getCruiseSpeed() const { return spec.cruiseSpeed; }
double EchoEVTOL::getBatteryCapacity() const { return spec.batteryCapacity; }
double EchoEVTOL::getChargeTime() const { return spec.chargeTime; }
double EchoEVTOL::getEnergyUsePerMile() const { return spec.energyUsePerMile; }
int EchoEVTOL::getPassengerCount() const { return spec.passengerCount; }
double EchoEVTOL::getFaultProbabilityPerHour() const { return spec.faultProbability; }
double EchoEVTOL::getRemainingBattery() const { return battery; }
void EchoEVTOL::resetBattery() { battery = spec.batteryCapacity; }
