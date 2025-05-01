#pragma once
#include <bridge/include/bridge.h>
#include <print>
class Bus : public IVehicle
{
public:
    explicit Bus(const IEngine &engine) : IVehicle(engine) {};

protected:
    virtual void driveVehicle() const override
    {
        std::print("Starting Bus!\n");
    }
};
