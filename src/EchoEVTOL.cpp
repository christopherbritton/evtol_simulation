#include "EchoEVTOL.hpp"
#include <algorithm>
#include <cstring>

// Simulates flight for a given duration.
// hours: time in flight [hours]
void EchoEVTOL::fly(double hours) {
    double miles = cruiseSpeed * hours;                      // [miles] = [mph] * [hr]
    double energyUsed = miles * energyUsePerMile;           // [kWh] = [miles] * [kWh/mile]
    batteryLevel = std::max(0.0, batteryLevel - energyUsed);
    charging = false;
}

// Flags the vehicle as charging.
void EchoEVTOL::charge() {
    batteryLevel = batteryCapacity;
    charging = false;
}

// Checks if the battery level is below 10% of capacity.
bool EchoEVTOL::needsCharge() const {
    return batteryLevel < (batteryCapacity * 0.1);           // Threshold: 10% of capacity
}

// Accessor for cruise speed in miles per hour.
double EchoEVTOL::getCruiseSpeed() const {
    return cruiseSpeed;                                      // [mph]
}

// Accessor for battery capacity.
double EchoEVTOL::getBatteryCapacity() const {
    return batteryCapacity;                                  // [kWh]
}

// Accessor for time required to fully charge.
double EchoEVTOL::getChargeTime() const {
    return chargeTime;                                       // [hours]
}

// Accessor for energy usage per mile.
double EchoEVTOL::getEnergyUsePerMile() const {
    return energyUsePerMile;                                 // [kWh/mile]
}

// Accessor for passenger count.
int EchoEVTOL::getPassengerCount() const {
    return passengerCount;                                   // [passengers]
}

// Accessor for fault probability per hour.
double EchoEVTOL::getFaultProbabilityPerHour() const {
    return faultProbability;                                 // [unitless, probability/hour]
}

// Returns whether the vehicle is currently charging.
bool EchoEVTOL::isCharging() const {
    return charging;
}

// Accessor for charge rate.
double EchoEVTOL::getChargeRate() const {
    return chargeRate;                                       // [kWh/hour]
}

// Accessor for current battery level.
double EchoEVTOL::getBatteryLevel() const {
    return batteryLevel;                                     // [kWh]
}

// Simulates battery charging over time.
// Time complexity: O(1), Space complexity: O(1)
// hours: duration of charging [hours]
void EchoEVTOL::charge(double hours) {
    if (charging) {
        batteryLevel = std::min(batteryCapacity, batteryLevel + chargeRate * hours);
    }
}

// Resets battery to full capacity.
void EchoEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;                          // [kWh]
    charging = false;
}

// Accessor for total passenger capacity.
int EchoEVTOL::getPassengerCapacity() const {
    return passengerCount;                                   // [passengers]
}

// Returns the vehicle type.
const char* EchoEVTOL::getType() const {
    return "Echo";
}

// Fault simulation based on probability.
// Returns true if a random value is less than faultProbability.
bool EchoEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability;
}

// Returns remaining battery level.
double EchoEVTOL::getRemainingBattery() const {
    return batteryLevel;                                     // [kWh]
}