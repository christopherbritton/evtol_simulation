#include "Statistics.hpp"
#include <random>

void Statistics::reset() {
    totalFlightTime = 0.0;
    totalDistance = 0.0;
    totalChargeTime = 0.0;
    totalFaults = 0;
    totalPassengerMiles = 0.0;
    flights = 0;
    charges = 0;
}

void Statistics::update(Statistics& s, EVTOL* v, double hours, std::mt19937& gen) {
    double cruiseSpeed = v->getCruiseSpeed();
    double distance = cruiseSpeed * hours;
    v->fly(hours);
    s.totalFlightTime += hours;
    s.totalDistance += distance;
    s.totalPassengerMiles += distance * v->getPassengerCount();
    s.flights++;

    std::bernoulli_distribution faultDist(v->getFaultProbabilityPerHour() * hours);
    if (faultDist(gen)) s.totalFaults++;
}
