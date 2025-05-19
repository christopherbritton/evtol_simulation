#pragma once
#include <vector>
#include <utility>
// Records and reports EVTOL fault data
class FaultManager {
public:
    void recordFault(int evtolId, int faultCode);  // Time: O(1) amortized, Space: O(f)
    void report() const;                           // Time: O(f), Space: O(f)
private:
    std::vector<std::pair<int, int>> faults;
};
