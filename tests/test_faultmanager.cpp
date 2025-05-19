
#include "FaultManager.hpp"
#include <iostream>
#include <cassert>

// Unit test for FaultManager
// Time Complexity: O(n), where n = number of faults added
// Space Complexity: O(n), stores n fault entries
int main() {
    FaultManager fm;
    fm.recordFault(1, 101);
    fm.recordFault(2, 202);
    fm.recordFault(3, 303);

    std::cout << "FaultManager test completed (check output below):\n";
    fm.report();

    return 0;
}
