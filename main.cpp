#include <iostream>
#include <vector>
#include <random>
#include "VehicleType.hpp"
#include "FleetManager.hpp"
#include "ChargerManager.hpp"
#include "Simulation.hpp"
#include "StatisticsManager.hpp"

int main() {
    std::vector<VehicleType> types;
    types.push_back({"Alpha", 120, 320, 0.6, 1.6, 4, 0.25});
    types.push_back({"Bravo", 100, 100, 0.2, 1.5, 5, 0.10});
    types.push_back({"Charlie", 160, 220, 0.8, 2.2, 3, 0.05});
    types.push_back({"Delta", 90, 120, 0.62, 0.8, 2, 0.22});
    types.push_back({"Echo", 30, 150, 0.3, 5.8, 2, 0.61});

    std::random_device rd;
    std::default_random_engine rng(rd());

    FleetManager fleetManager(types, rng);
    std::vector<EVTOL>& fleet = fleetManager.getFleet();

    ChargerManager chargers(3);
    Simulation simulation(fleet, chargers, rng, 180.0, 1.0);
    simulation.run();

    StatisticsManager stats;
    stats.collect(fleet);
    stats.report();

    return 0;
}