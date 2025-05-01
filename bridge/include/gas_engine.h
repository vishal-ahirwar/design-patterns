#pragma once
#include <bridge/include/bridge.h>
#include <print>
class GasEngine : public IEngine
{
public:
    virtual void start() const override
    {
        std::print("[Gas Engine] : ");
    }
};
