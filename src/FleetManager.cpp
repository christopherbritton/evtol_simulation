
#include "FleetManager.hpp"
#include "EVTOL.hpp"

// Constructs a randomized fleet
FleetManager::FleetManager(const std::vector<VehicleType>& types,
                           std::default_random_engine& rng,
                           const std::map<VehicleType, VehicleProfile>& profiles) {
    std::uniform_int_distribution<size_t> dist(0, types.size() - 1);
    for (int i = 1; i <= 20; ++i) {
        VehicleType type = types[dist(rng)];
        const VehicleProfile& profile = profiles.at(type);
        fleet.emplace_back(i, type, profile);
    }
}

// Returns reference to fleet
std::vector<EVTOL>& FleetManager::getFleet() {
    return fleet;
}
