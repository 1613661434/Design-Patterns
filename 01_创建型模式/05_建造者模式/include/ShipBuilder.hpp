#pragma once

// ============================================================================
// 抽象建造者 (Builder)
// 定义构建产品各部分的接口
// ============================================================================
class ShipBuilder
{
public:
    virtual void reset() = 0;
    virtual void buildBody() = 0;
    virtual void buildWeapon() = 0;
    virtual void buildEngine() = 0;
    virtual void buildInterior() = 0;
    virtual ~ShipBuilder() = default;
};
