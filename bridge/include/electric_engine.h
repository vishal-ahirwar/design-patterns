#pragma once
#include <bridge/include/bridge.h>
#include <print>
class ElectricEngine : public IEngine
{
public:
    virtual void start() const override
    {
        std::print("[Electric Engine] : ");
    }
};
