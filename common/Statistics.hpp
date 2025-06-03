#pragma once
#include "EVTOL.hpp"
#include <random>

struct Statistics {
    double totalFlightTime = 0.0;
    double totalDistance = 0.0;
    double totalChargeTime = 0.0;
    int totalFaults = 0;
    double totalPassengerMiles = 0.0;
    int flights = 0;
    int charges = 0;
    void reset();
    static void update(Statistics& s, EVTOL* v, double hours, std::mt19937& gen);
};
