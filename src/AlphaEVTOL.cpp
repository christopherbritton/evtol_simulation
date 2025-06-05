#include "AlphaEVTOL.hpp"
#include <algorithm>
#include <cstring>

// Simulates flying the EVTOL for a given number of hours.
// Units: hours (input), miles (distance), kWh (energy)
void AlphaEVTOL::fly(double hours) {
    double miles = cruiseSpeed * hours;                      // [miles] = [mph] * [hours]
    double energyUsed = miles * energyUsePerMile;           // [kWh] = [miles] * [kWh/mile]
    batteryLevel = std::max(0.0, batteryLevel - energyUsed); // Ensure battery doesn't go below 0
    charging = false;                                       // Vehicle is not charging during flight
}

// Initiates charging state
void AlphaEVTOL::charge() {
    batteryLevel = batteryCapacity;
    charging = false;
}

// Checks if battery level is below 10% of full capacity
bool AlphaEVTOL::needsCharge() const {
    return batteryLevel < (batteryCapacity * 0.1);           // [kWh]
}

// Returns cruise speed
double AlphaEVTOL::getCruiseSpeed() const {
    return cruiseSpeed;                                     // [mph]
}

// Returns total battery capacity
double AlphaEVTOL::getBatteryCapacity() const {
    return batteryCapacity;                                 // [kWh]
}

// Returns the time required to fully charge the vehicle
double AlphaEVTOL::getChargeTime() const {
    return chargeTime;                                      // [hours]
}

// Returns energy use per mile
double AlphaEVTOL::getEnergyUsePerMile() const {
    return energyUsePerMile;                                // [kWh/mile]
}

// Returns current number of passengers onboard
int AlphaEVTOL::getPassengerCount() const {
    return passengerCount;                                  // [passengers]
}

// Returns fault probability per hour of operation
double AlphaEVTOL::getFaultProbabilityPerHour() const {
    return faultProbability;                                // [probability/hour]
}

// Checks if the vehicle is currently charging
bool AlphaEVTOL::isCharging() const {
    return charging;
}

// Returns charge rate of the battery
double AlphaEVTOL::getChargeRate() const {
    return chargeRate;                                      // [kWh/hour]
}

// Returns current battery level
double AlphaEVTOL::getBatteryLevel() const {
    return batteryLevel;                                    // [kWh]
}

// Simulates charging the vehicle for a certain number of hours
// Units: hours (input), kWh (battery level)
void AlphaEVTOL::charge(double hours) {
    if (charging) {
        batteryLevel = std::min(batteryCapacity, batteryLevel + chargeRate * hours);
    }
}

// Fully resets the battery to max capacity and stops charging
void AlphaEVTOL::resetBattery() {
    batteryLevel = batteryCapacity;                         // [kWh]
    charging = false;
}

// Returns the total passenger capacity
int AlphaEVTOL::getPassengerCapacity() const {
    return passengerCount;                                  // [passengers]
}

// Returns type identifier
const char* AlphaEVTOL::getType() const {
    return "Alpha";
}

// Simulates a random fault check using probability
bool AlphaEVTOL::checkForFault() const {
    return ((double) rand() / RAND_MAX) < faultProbability; // [unitless]
}

// Returns remaining battery energy
double AlphaEVTOL::getRemainingBattery() const {
    return batteryLevel;                                    // [kWh]
}
