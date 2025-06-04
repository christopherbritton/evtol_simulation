#include "DeltaEVTOL.hpp"
#include <algorithm>
#include <cstring>

// Simulates flight for the given duration in hours.
// Energy consumed is cruiseSpeed [mph] * energyUsePerMile [kWh/mile] * time [hr] = energyUsed [kWh]
// Time complexity: O(1), Space complexity: O(1)
void DeltaEVTOL::fly(double hours) {
    double energyUsed = hours * cruiseSpeed * energyUsePerMile;
    batteryLevel = std::max(0.0, batteryLevel - energyUsed);
    charging = false;
}

// Fully charges the battery.
// Time complexity: O(1), Space complexity: O(1)
void DeltaEVTOL::charge() {
    batteryLevel = batteryCapacity;
    charging = false;
}

// Determines whether a charge is needed based on 20% threshold.
// Time complexity: O(1), Space complexity: O(1)
bool DeltaEVTOL::needsCharge() const {
    return batteryLevel < (0.2 * batteryCapacity);
}

// Returns cruise speed in miles per hour [mph].
double DeltaEVTOL::getCruiseSpeed() const {
    return cruiseSpeed;
}

// Returns battery capacity in kilowatt-hours [kWh].
double DeltaEVTOL::getBatteryCapacity() const {
    return batteryCapacity;
}

// Returns time required to fully charge in hours [hr].
double DeltaEVTOL::getChargeTime() const {
    return chargeTime;
}

// Returns energy usage per mile in kilowatt-hours per mile [kWh/mile].
double DeltaEVTOL::getEnergyUsePerMile() const {
    return energyUsePerMile;
}

// Returns number of passengers currently onboard.
int DeltaEVTOL::getPassengerCount() const {
    return passengerCount;
}

// Returns probability of failure per hour (unitless probability value).
double DeltaEVTOL::getFaultProbabilityPerHour() const {
    return faultProbability;
}

// Returns whether the vehicle is currently charging.
bool DeltaEVTOL::isCharging() const {
    return charging;
}

// Returns charging rate in kilowatts [kW].
double DeltaEVTOL::getChargeRate() const {
    return chargeRate;
}

// Returns current battery level in kilowatt-hours [kWh].
double DeltaEVTOL::getBatteryLevel() const {
    return batteryLevel;
}

// Partially charges the battery for the given time.
// batteryLevel += hours [hr] * chargeRate [kW] = energyAdded [kWh]
// Time complexity: O(1), Space complexity: O(1)
void DeltaEVTOL::charge(double hours) {
    batteryLevel = std::min(batteryCapacity, batteryLevel + hours * chargeRate);
    charging = true;
}

// Resets battery level to full capacity.
void DeltaEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;
    charging = false;
}

// Returns maximum passenger capacity.
int DeltaEVTOL::getPassengerCapacity() const {
    return passengerCount;
}

// Returns vehicle type as string.
const char* DeltaEVTOL::getType() const {
    return "Delta";
}

// Simulates probabilistic fault occurrence.
// Returns true if random probability < faultProbability.
bool DeltaEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability;
}

// Returns remaining battery in kilowatt-hours [kWh].
double DeltaEVTOL::getRemainingBattery() const {
    return batteryLevel;
}
