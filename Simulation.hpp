#pragma once
#include <vector>
#include <random>
#include "EVTOL.hpp"
#include "ChargerManager.hpp"

class Simulation {
public:
    Simulation(std::vector<EVTOL>& fleet, ChargerManager& chargers, std::default_random_engine& rng, double duration, double timestep);
    void run();

private:
    std::vector<EVTOL>& fleet;
    ChargerManager& chargers;
    std::default_random_engine& rng;
    double duration;
    double timestep;
};

inline Simulation::Simulation(std::vector<EVTOL>& fleet, ChargerManager& chargers, std::default_random_engine& rng, double duration, double timestep)
    : fleet(fleet), chargers(chargers), rng(rng), duration(duration), timestep(timestep) {}

inline void Simulation::run() {
    for (int t = 0; t < duration; t += timestep) {
        std::vector<EVTOL*> fleetPtrs;
        for (std::vector<EVTOL>::iterator it = fleet.begin(); it != fleet.end(); ++it) {
            it->update(timestep, rng);
            fleetPtrs.push_back(&(*it));
        }
        chargers.assignChargers(fleetPtrs);
    }
}