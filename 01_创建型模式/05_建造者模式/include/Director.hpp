#pragma once

#include "ShipBuilder.hpp"

// ============================================================================
// 导演类 (Director)
// 控制产品的构建流程，调用建造者的方法按顺序构造产品
// 不依赖具体的建造者类型，只依赖抽象 Builder 接口
// ============================================================================
class Director
{
public:
    void setBuilder(ShipBuilder* builder)
    {
        m_builder = builder;
    }

    // 简约型：只有船体和动力
    void buildSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }

    // 标准型：船体 + 动力 + 武器
    void buildStandardShip()
    {
        buildSimpleShip();
        m_builder->buildWeapon();
    }

    // 豪华型：船体 + 动力 + 武器 + 内室
    void buildRegalShip()
    {
        buildStandardShip();
        m_builder->buildInterior();
    }

private:
    ShipBuilder* m_builder = nullptr;
};
