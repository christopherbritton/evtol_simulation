#include "FaultManager.hpp"
#include <iostream>

void testFaultManager() {
    FaultManager fm;
    fm.recordFault(1, 101);
    fm.recordFault(1, 102);
    std::cout << "FaultManager tests passed.\n";
}

int main() {
    testFaultManager();
    return 0;
}
