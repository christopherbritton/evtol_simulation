#include "AlphaEVTOL.hpp"
#include <algorithm>
#include <cstring>

// Simulates flying the EVTOL for a given number of hours.
// Time complexity: O(1)
// Space complexity: O(1)
// Units: hours (input), miles (distance), kWh (energy)
void AlphaEVTOL::fly(double hours) {
    double miles = cruiseSpeed * hours;                      // [miles] = [mph] * [hours]
    double energyUsed = miles * energyUsePerMile;           // [kWh] = [miles] * [kWh/mile]
    batteryLevel = std::max(0.0, batteryLevel - energyUsed); // Ensure battery doesn't go below 0
    charging = false;                                       // Vehicle is not charging during flight
}

// Initiates charging state
// Time complexity: O(1)
void AlphaEVTOL::charge() {
    charging = true;
}

// Checks if battery level is below 10% of full capacity
// Time complexity: O(1)
bool AlphaEVTOL::needsCharge() const {
    return batteryLevel < (batteryCapacity * 0.1);           // [kWh]
}

// Returns cruise speed
// Time complexity: O(1)
double AlphaEVTOL::getCruiseSpeed() const {
    return cruiseSpeed;                                     // [mph]
}

// Returns total battery capacity
// Time complexity: O(1)
double AlphaEVTOL::getBatteryCapacity() const {
    return batteryCapacity;                                 // [kWh]
}

// Returns the time required to fully charge the vehicle
// Time complexity: O(1)
double AlphaEVTOL::getChargeTime() const {
    return chargeTime;                                      // [hours]
}

// Returns energy use per mile
// Time complexity: O(1)
double AlphaEVTOL::getEnergyUsePerMile() const {
    return energyUsePerMile;                                // [kWh/mile]
}

// Returns current number of passengers onboard
// Time complexity: O(1)
int AlphaEVTOL::getPassengerCount() const {
    return passengerCount;                                  // [passengers]
}

// Returns fault probability per hour of operation
// Time complexity: O(1)
double AlphaEVTOL::getFaultProbabilityPerHour() const {
    return faultProbability;                                // [probability/hour]
}

// Checks if the vehicle is currently charging
// Time complexity: O(1)
bool AlphaEVTOL::isCharging() const {
    return charging;
}

// Returns charge rate of the battery
// Time complexity: O(1)
double AlphaEVTOL::getChargeRate() const {
    return chargeRate;                                      // [kWh/hour]
}

// Returns current battery level
// Time complexity: O(1)
double AlphaEVTOL::getBatteryLevel() const {
    return batteryLevel;                                    // [kWh]
}

// Simulates charging the vehicle for a certain number of hours
// Time complexity: O(1)
// Units: hours (input), kWh (battery level)
void AlphaEVTOL::charge(double hours) {
    if (charging) {
        batteryLevel = std::min(batteryCapacity, batteryLevel + chargeRate * hours);
    }
}

// Fully resets the battery to max capacity and stops charging
// Time complexity: O(1)
void AlphaEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;                         // [kWh]
    charging = false;
}

// Returns the total passenger capacity
// Time complexity: O(1)
int AlphaEVTOL::getPassengerCapacity() const {
    return passengerCount;                                  // [passengers]
}

// Returns type identifier
// Time complexity: O(1)
const char* AlphaEVTOL::getType() const {
    return "Alpha";
}

// Simulates a random fault check using probability
// Time complexity: O(1)
bool AlphaEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability; // [unitless]
}

// Returns remaining battery energy
// Time complexity: O(1)
double AlphaEVTOL::getRemainingBattery() const {
    return batteryLevel;                                    // [kWh]
}
