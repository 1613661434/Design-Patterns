#pragma once

#include <string>

// ============================================================================
// 抽象工厂模式 (Abstract Factory Pattern)
// 产品族: 船体 (ShipBody)
// ============================================================================

// 抽象船体产品
class ShipBody
{
public:
    virtual std::string getShipBody() = 0;
    virtual ~ShipBody() = default;
};

// 具体产品：木质船体
class WoodBody : public ShipBody
{
public:
    std::string getShipBody() override
    {
        return std::string("用<木材>制作轮船船体...");
    }
};

// 具体产品：钢铁船体
class IronBody : public ShipBody
{
public:
    std::string getShipBody() override
    {
        return std::string("用<钢铁>制作轮船船体...");
    }
};

// 具体产品：合金船体
class MetalBody : public ShipBody
{
public:
    std::string getShipBody() override
    {
        return std::string("用<合金>制作轮船船体...");
    }
};
