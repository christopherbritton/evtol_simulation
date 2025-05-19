#include "EVTOL.hpp"

EVTOL::EVTOL(const VehicleType& type) : type(type), battery(type.batteryCapacity), state("flying"), timeInState(0) {}

void EVTOL::update(double dt, std::default_random_engine& rng) {
    timeInState += dt;
    if (state == "flying") {
        double energyUsed = type.cruiseSpeed * type.energyUse * dt / 60.0;
        battery -= energyUsed;
        stats.totalFlightTime += dt;
        stats.totalDistance += type.cruiseSpeed * dt / 60.0;
        stats.passengerMiles += type.passengers * type.cruiseSpeed * dt / 60.0;
        if (battery <= 0) {
            state = "waiting";
            battery = 0;
            stats.flightCount++;
            timeInState = 0;
        }
        std::bernoulli_distribution fault(type.faultProb * dt / 60.0);
        if (fault(rng)) stats.faultCount++;
    } else if (state == "charging") {
        if (timeInState >= type.chargeTime * 60.0) {
            battery = type.batteryCapacity;
            startFlight();
        }
    }
}

bool EVTOL::isWaiting() const { return state == "waiting"; }
bool EVTOL::isCharging() const { return state == "charging"; }
bool EVTOL::isFlying() const { return state == "flying"; }

void EVTOL::startCharging() {
    state = "charging";
    stats.totalChargeTime += timeInState;
    stats.chargeCount++;
    timeInState = 0;
}

void EVTOL::startFlight() {
    state = "flying";
    timeInState = 0;
}

std::string EVTOL::getCompany() const { return type.name; }