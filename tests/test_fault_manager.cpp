#include "FaultManager.hpp"
#include <iostream>
#include <cassert>

// Test recording multiple faults and verifying their storage
bool testRecordFault() {
    FaultManager fm;
    fm.recordFault(1, 101);
    fm.recordFault(2, 202);

    if (fm.getAllFaults().size() != 2) {
        std::cerr << "❌ testRecordFault failed: expected 2 faults, got " << fm.getAllFaults().size() << "\n";
        return false;
    }
    std::cout << "✅ testRecordFault passed\n";
    return true;
}

// Test retrieving faults when none have been recorded
bool testGetAllFaults() {
    FaultManager fm;
    if (!fm.getAllFaults().empty()) {
        std::cerr << "❌ testGetAllFaults failed: expected empty fault list\n";
        return false;
    }
    std::cout << "✅ testGetAllFaults passed\n";
    return true;
}

// Main entry to execute all FaultManager tests
int main() {
    int failed = 0;
    if (!testGetAllFaults()) {
        std::cerr << "FAILED: testGetAllFaults\n";
        ++failed;
    }
    if (!testRecordFault()) {
        std::cerr << "FAILED: testRecordFault\n";
        ++failed;
    }

    if (failed == 0) {
        std::cout << "\n✅ All FaultManager tests passed\n";
        return 0;
    } else {
        std::cerr << "\n❌ " << failed << " FaultManager test(s) failed\n";
        return 1;
    }
}
