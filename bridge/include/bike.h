#pragma once
#include <bridge/include/bridge.h>
#include <print>
class Bike : public IVehicle
{
public:
    explicit Bike(const IEngine &engine) : IVehicle(engine) {};

protected:
    virtual void driveVehicle() const override
    {
        std::print("Starting Bike!\n");
    }
};
