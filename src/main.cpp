#include "Config.hpp"
#include "FleetManager.hpp"

int main() {
    FleetManager manager;
    manager.generateFleet(Config::FleetSize);

    manager.simulate(Config::SimulationDurationHours, Config::SimulationStepHours);

    manager.printStatistics(true);
    return 0;
}
