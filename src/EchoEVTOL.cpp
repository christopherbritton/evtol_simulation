#include "EchoEVTOL.hpp"

// Simulates a flight by reducing battery based on distance and energy use
void EchoEVTOL::fly(double hours) {
    double distance = spec.cruiseSpeed * hours;                 // [miles] distance = speed * time
    battery -= distance * spec.energyUsePerMile;               // [kWh] energy consumed for the flight
}

// Fully recharges the battery
void EchoEVTOL::charge() {
    battery = spec.batteryCapacity;                            // [kWh]
}

// Checks if the battery has been depleted
bool EchoEVTOL::needsCharge() const {
    return battery <= 0;
}

// Accessors for Echo vehicle specifications

// [mph] Cruise speed of the Echo EVTOL
double EchoEVTOL::getCruiseSpeed() const { return spec.cruiseSpeed; }

// [kWh] Battery storage capacity
double EchoEVTOL::getBatteryCapacity() const { return spec.batteryCapacity; }

// [hours] Required charging time
double EchoEVTOL::getChargeTime() const { return spec.chargeTime; }

// [kWh/mile] Energy consumption per mile
double EchoEVTOL::getEnergyUsePerMile() const { return spec.energyUsePerMile; }

// [count] Number of passengers supported
int EchoEVTOL::getPassengerCount() const { return spec.passengerCount; }

// [probability/hour] Chance of failure per hour
double EchoEVTOL::getFaultProbabilityPerHour() const { return spec.faultProbability; }

// [kWh] Remaining battery charge
double EchoEVTOL::getRemainingBattery() const { return battery; }

// Resets the battery to full charge
void EchoEVTOL::resetBattery() { battery = spec.batteryCapacity; }