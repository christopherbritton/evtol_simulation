#include "BravoEVTOL.hpp"

// Simulates flight by reducing battery based on speed and energy usage
void BravoEVTOL::fly(double hours) {
    double distance = spec.cruiseSpeed * hours;                 // [miles] distance = speed * time
    battery -= distance * spec.energyUsePerMile;               // [kWh] battery drained by energy per mile
}

// Charges the EVTOL to full battery capacity
void BravoEVTOL::charge() {
    battery = spec.batteryCapacity;                            // [kWh]
}

// Checks if battery is depleted and charging is needed
bool BravoEVTOL::needsCharge() const {
    return battery <= 0;
}

// Accessor methods for vehicle specification parameters

// [mph] Cruise speed of the vehicle
double BravoEVTOL::getCruiseSpeed() const { return spec.cruiseSpeed; }

// [kWh] Maximum battery capacity
double BravoEVTOL::getBatteryCapacity() const { return spec.batteryCapacity; }

// [hours] Time required to fully charge battery
double BravoEVTOL::getChargeTime() const { return spec.chargeTime; }

// [kWh/mile] Energy usage rate during flight
double BravoEVTOL::getEnergyUsePerMile() const { return spec.energyUsePerMile; }

// [count] Number of passengers supported
int BravoEVTOL::getPassengerCount() const { return spec.passengerCount; }

// [probability/hour] Failure likelihood per hour of operation
double BravoEVTOL::getFaultProbabilityPerHour() const { return spec.faultProbability; }

// [kWh] Current state of battery
double BravoEVTOL::getRemainingBattery() const { return battery; }

// Recharges battery to maximum capacity
void BravoEVTOL::resetBattery() { battery = spec.batteryCapacity; }
