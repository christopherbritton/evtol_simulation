#include "AlphaEVTOL.hpp"

// Simulates flight for a given duration by consuming energy based on cruise speed and energy usage rate
void AlphaEVTOL::fly(double hours) {
    double distance = spec.cruiseSpeed * hours;                 // [miles] distance = speed * time
    battery -= distance * spec.energyUsePerMile;               // [kWh] battery drained by energy per mile
}

// Charges the EVTOL to full battery capacity
void AlphaEVTOL::charge() {
    battery = spec.batteryCapacity;                            // [kWh]
}

// Checks whether the battery is depleted and charging is required
bool AlphaEVTOL::needsCharge() const {
    return battery <= 0;
}

// Accessor methods for vehicle specification parameters

// [mph] Cruise speed of the vehicle
double AlphaEVTOL::getCruiseSpeed() const { return spec.cruiseSpeed; }

// [kWh] Maximum battery capacity
double AlphaEVTOL::getBatteryCapacity() const { return spec.batteryCapacity; }

// [hours] Time required to charge from 0 to 100%
double AlphaEVTOL::getChargeTime() const { return spec.chargeTime; }

// [kWh/mile] Energy usage rate while flying
double AlphaEVTOL::getEnergyUsePerMile() const { return spec.energyUsePerMile; }

// [count] Number of passengers supported
int AlphaEVTOL::getPassengerCount() const { return spec.passengerCount; }

// [probability/hour] Likelihood of failure per flight hour
double AlphaEVTOL::getFaultProbabilityPerHour() const { return spec.faultProbability; }

// [kWh] Current battery level
double AlphaEVTOL::getRemainingBattery() const { return battery; }

// Resets battery to full capacity
void AlphaEVTOL::resetBattery() { battery = spec.batteryCapacity; }
