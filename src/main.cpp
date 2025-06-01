#include "FleetManager.hpp"

int main() {
    FleetManager manager;
    manager.generateFleet(20);

    const double simDuration = 3.0;
    const double step = 0.1;

    for (double t = 0; t < simDuration; t += step) {
        manager.simulateStep(step);
    }

    manager.printStatistics();
    return 0;
}
