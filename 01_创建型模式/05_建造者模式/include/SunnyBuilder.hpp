#pragma once

#include "ShipBuilder.hpp"
#include "Ships.hpp"

// ============================================================================
// 具体建造者: 桑尼号建造者 (Concrete Builder)
// 实现 ShipBuilder 接口，构建桑尼号的各个部件
// ============================================================================
class SunnyBuilder : public ShipBuilder
{
public:
    SunnyBuilder()
    {
        reset();
    }

    ~SunnyBuilder()
    {
        if (m_sunny != nullptr)
        {
            delete m_sunny;
        }
    }

    // 提供重置函数, 目的是能够使用生成器对象生成多个产品
    void reset() override
    {
        m_sunny = new SunnyShip;
    }

    void buildBody() override
    {
        m_sunny->addParts("神树亚当的树干");
    }

    void buildWeapon() override
    {
        m_sunny->addParts("狮吼炮");
    }

    void buildEngine() override
    {
        m_sunny->addParts("可乐驱动");
    }

    void buildInterior() override
    {
        m_sunny->addParts("豪华内室精装");
    }

    // 获取构建的产品，移交所有权，置空内部指针
    SunnyShip* getSunny()
    {
        SunnyShip* ship = m_sunny;
        m_sunny = nullptr;
        return ship;
    }

private:
    SunnyShip* m_sunny = nullptr;
};
