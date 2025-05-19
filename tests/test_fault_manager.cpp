#include "../FaultManager.hpp"
#include <iostream>

void test_recordFault() {
    FaultManager fm;
    fm.recordFault(2, 500);
    fm.report();
    std::cout << "test_recordFault passed\n";
}

int main() {
    test_recordFault();
    return 0;
}
