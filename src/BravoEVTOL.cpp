#include "BravoEVTOL.hpp"
#include <algorithm>
#include <cstring>

// Simulates flight for a given number of hours.
// Time Complexity: O(1), Space Complexity: O(1)
// Units: hours for time, miles for distance, kWh for energy
void BravoEVTOL::fly(double hours) {
    double distance = cruiseSpeed * hours;                             // [miles]
    double energyUsed = distance * energyUsePerMile;                  // [kWh]
    batteryLevel -= energyUsed;
    charging = false;
}

// Fully recharges the battery.
// Time Complexity: O(1), Space Complexity: O(1)
void BravoEVTOL::charge() {
    batteryLevel = batteryCapacity;                                   // [kWh]
    charging = false;
}

// Determines if the vehicle needs charging (below 25% threshold).
// Time Complexity: O(1), Space Complexity: O(1)
bool BravoEVTOL::needsCharge() const {
    return batteryLevel < batteryCapacity * 0.25;                     // [kWh]
}

// Getters - Time Complexity: O(1), Space Complexity: O(1)
double BravoEVTOL::getCruiseSpeed() const { return cruiseSpeed; }    // [mph]
double BravoEVTOL::getBatteryCapacity() const { return batteryCapacity; } // [kWh]
double BravoEVTOL::getChargeTime() const { return chargeTime; }      // [hours]
double BravoEVTOL::getEnergyUsePerMile() const { return energyUsePerMile; } // [kWh/mile]
int BravoEVTOL::getPassengerCount() const { return passengerCount; }
double BravoEVTOL::getFaultProbabilityPerHour() const { return faultProbability; } // [unitless probability]

bool BravoEVTOL::isCharging() const { return charging; }
double BravoEVTOL::getChargeRate() const { return chargeRate; }      // [kWh/hour]
double BravoEVTOL::getBatteryLevel() const { return batteryLevel; }  // [kWh]

// Charges the vehicle over a given number of hours.
// Time Complexity: O(1), Space Complexity: O(1)
// Units: hours for input, kWh for output
void BravoEVTOL::charge(double hours) {
    batteryLevel += chargeRate * hours;
    if (batteryLevel >= batteryCapacity) {
        batteryLevel = batteryCapacity;
        charging = false;
    } else {
        charging = true;
    }
}

// Resets the battery to full.
// Time Complexity: O(1), Space Complexity: O(1)
void BravoEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;
    charging = false;
}

// Returns max passenger capacity.
// Time Complexity: O(1), Space Complexity: O(1)
int BravoEVTOL::getPassengerCapacity() const {
    return passengerCount;
}

// Returns vehicle type.
// Time Complexity: O(1), Space Complexity: O(1)
const char* BravoEVTOL::getType() const {
    return "Bravo";
}

// Randomly determines if a fault occurred.
// Time Complexity: O(1), Space Complexity: O(1)
bool BravoEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability;
}

// Returns current battery level.
// Time Complexity: O(1), Space Complexity: O(1)
double BravoEVTOL::getRemainingBattery() const {
    return batteryLevel;                                              // [kWh]
}
