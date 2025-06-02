#include "CharlieEVTOL.hpp"

// Simulates flight by calculating distance and reducing battery based on energy usage rate
void CharlieEVTOL::fly(double hours) {
    double distance = spec.cruiseSpeed * hours;                 // [miles] distance = speed * time
    battery -= distance * spec.energyUsePerMile;               // [kWh] energy consumed during flight
}

// Charges the EVTOL to its full battery capacity
void CharlieEVTOL::charge() {
    battery = spec.batteryCapacity;                            // [kWh]
}

// Checks if the battery level is depleted and requires charging
bool CharlieEVTOL::needsCharge() const {
    return battery <= 0;
}

// Accessor methods for vehicle specification values

// [mph] Vehicle cruise speed
double CharlieEVTOL::getCruiseSpeed() const { return spec.cruiseSpeed; }

// [kWh] Maximum battery capacity
double CharlieEVTOL::getBatteryCapacity() const { return spec.batteryCapacity; }

// [hours] Time required to fully recharge the battery
double CharlieEVTOL::getChargeTime() const { return spec.chargeTime; }

// [kWh/mile] Energy usage per mile during flight
double CharlieEVTOL::getEnergyUsePerMile() const { return spec.energyUsePerMile; }

// [count] Number of passengers supported
int CharlieEVTOL::getPassengerCount() const { return spec.passengerCount; }

// [probability/hour] Likelihood of system failure per hour
double CharlieEVTOL::getFaultProbabilityPerHour() const { return spec.faultProbability; }

// [kWh] Current remaining battery level
double CharlieEVTOL::getRemainingBattery() const { return battery; }

// Resets battery to full charge
void CharlieEVTOL::resetBattery() { battery = spec.batteryCapacity; }
