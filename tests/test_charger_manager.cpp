#include "../ChargerManager.hpp"
#include "../EVTOL.hpp"
#include <iostream>

void test_assignCharger() {
    ChargerManager cm(2);
    EVTOL e1(1), e2(2), e3(3);
    cm.assignCharger(e1);
    cm.assignCharger(e2);
    cm.assignCharger(e3); // No charger available
    cm.update();          // Reset chargers
    cm.assignCharger(e3); // Should succeed
    cm.report();
    std::cout << "test_assignCharger passed\n";
}

int main() {
    test_assignCharger();
    return 0;
}
