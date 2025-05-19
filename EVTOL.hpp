#pragma once
// Represents an EVTOL vehicle and its runtime state
class EVTOL {
public:
    EVTOL(int id);                         // Constructor
    void simulateStep();                  // Time: O(1), Space: O(1) — Random state update
    bool hasFault() const;                // Time: O(1), Space: O(1)
    bool needsCharging() const;           // Time: O(1), Space: O(1)
    int getId() const;                    // Time: O(1), Space: O(1)
    int getFaultCode() const;             // Time: O(1), Space: O(1)
private:
    int id;
    bool fault;
    bool chargingNeeded;
    int faultCode;
    bool coinFlip(int odds);              // Time: O(1), Space: O(1)
};
