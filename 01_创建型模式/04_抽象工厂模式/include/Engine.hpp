#pragma once

#include <string>

// ============================================================================
// 产品族: 动力系统 (Engine)
// ============================================================================

// 抽象动力产品
class Engine
{
public:
    virtual std::string getEngine() = 0;
    virtual ~Engine() = default;
};

// 具体产品：人力驱动
class Human : public Engine
{
public:
    std::string getEngine() override
    {
        return std::string("使用<人力驱动>...");
    }
};

// 具体产品：内燃机驱动
class Diesel : public Engine
{
public:
    std::string getEngine() override
    {
        return std::string("使用<内燃机驱动>...");
    }
};

// 具体产品：核能驱动
class Nuclear : public Engine
{
public:
    std::string getEngine() override
    {
        return std::string("使用<核能驱动>...");
    }
};
