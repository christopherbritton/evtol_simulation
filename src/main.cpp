#include "Config.hpp"
#include "FleetManager.hpp"

int main() {
    FleetManager manager;

    // Generate a fleet of EVTOLs of size defined in Config
    // Time Complexity: O(n), where n = Config::FleetSize
    // Space Complexity: O(n), each EVTOL stored in a vector
    manager.generateFleet(Config::FleetSize);

    // Simulate the fleet over a total duration (in hours) with step granularity
    // Time Complexity: O(t * n), where t = total steps = SimulationDurationHours / SimulationStepHours
    // Space Complexity: O(1) additional per step
    // Bottleneck: simulateStep internally processes every EVTOL in the fleet per time step, including charge/fly logic and stat updates
    manager.simulate(Config::SimulationDurationHours, Config::SimulationStepHours);

    // Print overall statistics
    // Time Complexity: O(k), where k = number of unique EVTOL types
    // Space Complexity: O(1)
    manager.printStatistics(true);

    return 0;
}