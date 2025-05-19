
#pragma once
#include "EVTOL.hpp"
#include "VehicleType.hpp"
#include "VehicleProfile.hpp"
#include <vector>
#include <map>
#include <random>

// Manages creation of a fleet of EVTOLs from available vehicle types
class FleetManager {
public:
    FleetManager(const std::vector<VehicleType>& types,
                 std::default_random_engine& rng,
                 const std::map<VehicleType, VehicleProfile>& profiles);

    std::vector<EVTOL>& getFleet();

private:
    std::vector<EVTOL> fleet;
};
