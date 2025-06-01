#pragma once
#include "EVTOL.hpp"
#include "Config.hpp"

class EchoEVTOL : public EVTOL {
private:
    double battery;
    const Config::VehicleSpec spec;

public:
    EchoEVTOL() : battery(Config::EchoSpec.batteryCapacity), spec(Config::EchoSpec) {}

    void fly(double hours) override;
    void charge() override;
    bool needsCharge() const override;

    double getCruiseSpeed() const override;
    double getBatteryCapacity() const override;
    double getChargeTime() const override;
    double getEnergyUsePerMile() const override;
    int getPassengerCount() const override;
    double getFaultProbabilityPerHour() const override;

    double getRemainingBattery() const override;
    void resetBattery() override;
};
