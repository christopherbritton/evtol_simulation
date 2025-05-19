#pragma once
#include <string>
#include <random>
#include "VehicleType.hpp"

struct Statistics {
    double totalFlightTime = 0;
    double totalDistance = 0;
    double totalChargeTime = 0;
    int faultCount = 0;
    double passengerMiles = 0;
    int flightCount = 0;
    int chargeCount = 0;
};

class EVTOL {
public:
    EVTOL(const VehicleType& type);
    void update(double dt, std::default_random_engine& rng);
    bool isWaiting() const;
    bool isCharging() const;
    bool isFlying() const;
    void startCharging();
    void startFlight();
    Statistics stats;
    std::string getCompany() const;

private:
    VehicleType type;
    double battery;
    std::string state;
    double timeInState;
};