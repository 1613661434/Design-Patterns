#pragma once

#include "ShipBuilder.hpp"
#include "Ships.hpp"

// ============================================================================
// 具体建造者: 梅利号建造者 (Concrete Builder)
// 实现 ShipBuilder 接口，构建梅利号的各个部件
// ============================================================================
class MerryBuilder : public ShipBuilder
{
public:
    MerryBuilder()
    {
        reset();
    }

    ~MerryBuilder()
    {
        if (m_merry != nullptr)
        {
            delete m_merry;
        }
    }

    void reset() override
    {
        m_merry = new MerryShip;
    }

    void buildBody() override
    {
        m_merry->assemble("船体", "优质木材");
    }

    void buildWeapon() override
    {
        m_merry->assemble("武器", "四门大炮");
    }

    void buildEngine() override
    {
        m_merry->assemble("动力", "蒸汽机");
    }

    void buildInterior() override
    {
        m_merry->assemble("内室", "精装");
    }

    // 获取构建的产品，移交所有权，置空内部指针
    MerryShip* getMerry()
    {
        MerryShip* ship = m_merry;
        m_merry = nullptr;
        return ship;
    }

private:
    MerryShip* m_merry = nullptr;
};
