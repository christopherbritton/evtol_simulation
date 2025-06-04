#include "CharlieEVTOL.hpp"
#include <algorithm>
#include <cstring>

// Simulates flight for a given number of hours.
// Time complexity: O(1)
// Space complexity: O(1)
// Energy used = cruiseSpeed * hours * energyUsePerMile [kWh], Distance = cruiseSpeed * hours [miles]
void CharlieEVTOL::fly(double hours) {
    double distance = cruiseSpeed * hours;                             // [miles]
    double energyUsed = distance * energyUsePerMile;                  // [kWh]
    batteryLevel -= energyUsed;
    charging = false;
}

// Fully recharges the EVTOL battery.
// Time complexity: O(1)
// Space complexity: O(1)
void CharlieEVTOL::charge() {
    batteryLevel = batteryCapacity;                                   // Full recharge
    charging = false;
}

// Checks if charge is needed (battery < 25% of capacity).
// Time complexity: O(1)
// Space complexity: O(1)
bool CharlieEVTOL::needsCharge() const {
    return batteryLevel < batteryCapacity * 0.25;                     // Needs charge if < 25%
}

// Accessor methods to expose vehicle characteristics.
double CharlieEVTOL::getCruiseSpeed() const { return cruiseSpeed; }             // [mph]
double CharlieEVTOL::getBatteryCapacity() const { return batteryCapacity; }     // [kWh]
double CharlieEVTOL::getChargeTime() const { return chargeTime; }               // [hours]
double CharlieEVTOL::getEnergyUsePerMile() const { return energyUsePerMile; }   // [kWh/mile]
int CharlieEVTOL::getPassengerCount() const { return passengerCount; }          // [people]
double CharlieEVTOL::getFaultProbabilityPerHour() const { return faultProbability; } // [0-1]

bool CharlieEVTOL::isCharging() const { return charging; }
double CharlieEVTOL::getChargeRate() const { return chargeRate; }               // [kWh/hour]
double CharlieEVTOL::getBatteryLevel() const { return batteryLevel; }           // [kWh]

// Partial charging method for simulating time-based recharging.
// Time complexity: O(1)
// Space complexity: O(1)
void CharlieEVTOL::charge(double hours) {
    batteryLevel += chargeRate * hours;
    if (batteryLevel >= batteryCapacity) {
        batteryLevel = batteryCapacity;
        charging = false;
    } else {
        charging = true;
    }
}

// Resets the battery to full state.
// Time complexity: O(1)
// Space complexity: O(1)
void CharlieEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;
    charging = false;
}

// Returns passenger capacity of this EVTOL model.
int CharlieEVTOL::getPassengerCapacity() const {
    return passengerCount;
}

// Returns type of this EVTOL model.
const char* CharlieEVTOL::getType() const {
    return "Charlie";
} 

// Simulates fault based on fault probability.
// Time complexity: O(1)
// Space complexity: O(1)
bool CharlieEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability;
}

// Returns remaining battery energy.
double CharlieEVTOL::getRemainingBattery() const {
    return batteryLevel;                                              // [kWh]
}
