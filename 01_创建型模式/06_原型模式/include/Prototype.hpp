#pragma once

#include <iostream>
#include <string>

// ============================================================================
// 原型模式 (Prototype Pattern)
// 通过复制现有对象来创建新对象，而无需通过传统的构造函数。
//
// 抽象原型类：杰尔马超级士兵接口
// ============================================================================
class GermaSoldier
{
public:
    virtual GermaSoldier* clone() = 0;
    virtual std::string whoAmI() = 0;
    virtual ~GermaSoldier() = default;
};

// ============================================================================
// 具体原型类：杰尔马66超级士兵
// ============================================================================
class Soldier66 : public GermaSoldier
{
public:
    GermaSoldier* clone() override
    {
        return new Soldier66(*this);
    }
    std::string whoAmI() override
    {
        return std::string("我是杰尔马66的超级士兵!!!");
    }
};

// ============================================================================
// 具体原型类：杰尔马67超级士兵
// ============================================================================
class Soldier67 : public GermaSoldier
{
public:
    GermaSoldier* clone() override
    {
        return new Soldier67(*this);
    }
    std::string whoAmI() override
    {
        return std::string("我是杰尔马67的超级士兵!!!");
    }
};
