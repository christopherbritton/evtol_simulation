#include "../EVTOL.hpp"
#include <cassert>
#include <iostream>

void test_simulateStep() {
    EVTOL e(1);
    e.simulateStep();
    assert(e.getId() == 1);
    std::cout << "test_simulateStep passed\n";
}

int main() {
    test_simulateStep();
    return 0;
}
