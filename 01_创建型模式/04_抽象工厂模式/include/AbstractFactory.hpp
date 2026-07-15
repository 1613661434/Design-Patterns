#pragma once

#include "Ship.hpp"
#include <iostream>
#include <string>

// ============================================================================
// 抽象工厂：声明创建各产品族产品的方法
// ============================================================================
class AbstractFactory
{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory() = default;
};

// ============================================================================
// 具体工厂：基础型工厂 (木质船体 + 枪 + 人力驱动)
// ============================================================================
class BasicFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new WoodBody, new Gun, new Human);
        std::cout << "<基础型>战船生产完毕, 可以下水啦..." << std::endl;
        return ship;
    }
};

// ============================================================================
// 具体工厂：标准型工厂 (钢铁船体 + 自动机关炮 + 内燃机驱动)
// ============================================================================
class StandardFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new IronBody, new Cannon, new Diesel);
        std::cout << "<标准型>战船生产完毕, 可以下水啦..." << std::endl;
        return ship;
    }
};

// ============================================================================
// 具体工厂：旗舰型工厂 (合金船体 + 激光武器 + 核能驱动)
// ============================================================================
class UltimateFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new MetalBody, new Laser, new Nuclear);
        std::cout << "<旗舰型>战船生产完毕, 可以下水啦..." << std::endl;
        return ship;
    }
};
