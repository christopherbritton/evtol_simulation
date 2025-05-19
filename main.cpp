#include "EVTOL.hpp"
#include "ChargerManager.hpp"
#include "FaultManager.hpp"
#include "StatisticsTracker.hpp"
#include <iostream>
#include <vector>

// Entry point for the EVTOL simulation
int main() {
    // Initialize core managers
    ChargerManager chargerManager(4); // 4 available chargers
    FaultManager faultManager;
    StatisticsTracker statsTracker;

    // Create and register 8 EVTOLs
    // Time: O(1) per emplace_back, total O(n) for n EVTOLs
    // Space: O(n) for storing EVTOLs
    std::vector<EVTOL> evtols;
    for (int i = 1; i <= 8; ++i) {
        evtols.emplace_back(i);
    }

    // Run the simulation for 3 steps
    // Time: O(s × n) for s steps and n EVTOLs
    // Space: Mainly accumulative for stats and fault/charging logs (O(n) max)
    for (int step = 1; step <= 3; ++step) {
        std::cout << "\n--- Simulation Step " << step << " ---\n";

        // Simulate each EVTOL
        // Time: O(n)
        for (size_t i = 0; i < evtols.size(); ++i) {
            evtols[i].simulateStep();  // Time: O(1), Space: O(1)

            // Record fault if any
            if (evtols[i].hasFault()) {
                faultManager.recordFault(evtols[i].getId(), evtols[i].getFaultCode()); // Time: O(1) amortized, Space: O(f)
            }

            // Assign to charger if needed
            if (evtols[i].needsCharging()) {
                chargerManager.assignCharger(evtols[i]); // Time: O(1) amortized, Space: O(k) max active charges
            }
        }

        // Recharge and update statistics
        chargerManager.update();       // Time: O(k), Space: clears k charging slots
        statsTracker.record(evtols);   // Time: O(n), Space: O(1) for counters
    }

    // Display final reports
    statsTracker.report();  // Time: O(1), Space: O(1)
    faultManager.report();  // Time: O(f), Space: O(f)
    chargerManager.report();// Time: O(1), Space: O(1)

    return 0;
}
