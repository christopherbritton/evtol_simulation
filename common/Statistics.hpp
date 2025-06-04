#pragma once

#include "EVTOL.hpp"
#include <random>

class Statistics {
public:
    double totalFlightTime = 0.0;      // Total flight time in hours
    double totalDistance = 0.0;        // Total flight distance in miles
    double totalChargeTime = 0.0;      // Total time spent charging in hours
    int totalFaults = 0;               // Total number of faults encountered
    double totalPassengerMiles = 0.0;  // Total passenger miles
    int flights = 0;                   // Number of flights
    int charges = 0;                   // Number of charges

    // Resets all statistics to initial values
    void reset();

    // Updates the given statistics object using data from the EVTOL
    // - s: statistics object to update
    // - v: pointer to EVTOL object
    // - hours: duration of the flight in hours
    // - gen: random number generator used for fault simulation
    static void update(Statistics& s, EVTOL* v, double hours, std::mt19937& gen);
};
