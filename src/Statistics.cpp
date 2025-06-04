#include "Statistics.hpp"
#include <random>

// Resets all tracked statistics to initial state
void Statistics::reset() {
    totalFlightTime = 0.0;            // hours
    totalDistance = 0.0;              // miles
    totalChargeTime = 0.0;            // hours
    totalFaults = 0;                  // count
    totalPassengerMiles = 0.0;        // miles
    flights = 0;                      // count
    charges = 0;                      // count
}

// Updates the provided Statistics object based on the current EVTOL's flight
// Parameters:
//   - s: statistics object being updated
//   - v: pointer to the EVTOL vehicle
//   - hours: duration of flight in hours
//   - gen: random number generator for fault simulation
void Statistics::update(Statistics& s, EVTOL* v, double hours, std::mt19937& gen) {
    double cruiseSpeed = v->getCruiseSpeed();                                        // mph
    double distance = cruiseSpeed * hours;                                           // miles
    v->fly(hours);                                                                   // Simulate the flight
    s.totalFlightTime += hours;                                                      // hours
    s.totalDistance += distance;                                                     // miles
    s.totalPassengerMiles += distance * v->getPassengerCount();                      // miles * passengers
    s.flights++;                                                                     // increment flight count

    std::bernoulli_distribution faultDist(v->getFaultProbabilityPerHour() * hours);
    if (faultDist(gen)) s.totalFaults++;                                             // probabilistically add fault
}