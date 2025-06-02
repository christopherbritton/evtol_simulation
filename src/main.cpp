#include "FleetManager.hpp"

int main() {
    FleetManager manager;

    // Generate a fleet of 20 randomly selected EVTOLs
    // Time complexity: O(N), where N is the number of EVTOLs generated
    // Space complexity: O(N), each EVTOL is stored in memory
    manager.generateFleet(20);

    // [hours] Total duration of the simulation
    const double simDuration = 3.0;

    // [hours] Duration of each simulation time step
    const double step = 0.1;

    // Run simulation in steps until total duration is reached
    // Loop runs simDuration/step times -> O(T), where T is the number of steps
    // Each step simulates O(N) EVTOLs and performs charging logic
    // Overall time complexity: O(T * N)
    for (double t = 0; t < simDuration; t += step) {
        manager.simulateStep(step);  // Potential runtime bottleneck:
                                    // - Iterates over entire fleet (O(N))
                                    // - Applies fault simulation and battery logic
                                    // - Charging queue and stats tracking add overhead
    }

    // Output final simulation statistics
    manager.printStatistics();  // Time complexity: O(N), iterates over vehicle types and stats
    return 0;

    // Space complexity of main: dominated by fleet size O(N)
    // No significant memory reuse or deallocation between steps (no fleet shrinking)
}