#pragma once
#include <vector>
#include <random>
#include "EVTOL.hpp"
#include "VehicleType.hpp"

class FleetManager {
public:
    FleetManager(const std::vector<VehicleType>& types, std::default_random_engine& rng);
    std::vector<EVTOL>& getFleet();

private:
    std::vector<EVTOL> fleet;
};

inline FleetManager::FleetManager(const std::vector<VehicleType>& types, std::default_random_engine& rng) {
    std::bernoulli_distribution coinFlip(0.5);
    while (fleet.size() < 20) {
        for (std::vector<VehicleType>::const_iterator it = types.begin(); it != types.end(); ++it) {
            if (fleet.size() < 20 && coinFlip(rng)) {
                fleet.emplace_back(*it);
            }
        }
    }
}

inline std::vector<EVTOL>& FleetManager::getFleet() {
    return fleet;
}