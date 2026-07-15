#pragma once

#include <iostream>
#include <string>
#include <utility>

#include "AbstractTeam.hpp"

// =============================================================================
// 桥接模式 - Abstraction (抽象类): 船的抽象
// =============================================================================
// 定义"船"的抽象接口，持有实现部分(AbstractTeam)的引用。
// 通过组合而非继承的方式连接船与团队，两者可以独立扩展。

class AbstractShip {
public:
    explicit AbstractShip(AbstractTeam* team) : m_team(team) {}

    void showTeam() {
        m_team->show();
        m_team->executeTask();
    }

    virtual std::string getName() = 0;
    virtual void feature() = 0;
    virtual ~AbstractShip() {}

protected:
    AbstractTeam* m_team = nullptr;
};

// ---------------------------------------------------------------------------
// Refined Abstraction: 前进·梅利号
// ---------------------------------------------------------------------------
class Merry : public AbstractShip {
public:
    using AbstractShip::AbstractShip;
    std::string getName() override {
        return std::string("前进·梅利号");
    }
    void feature() override {
        std::cout << getName()
                  << " -- 船首为羊头, 在司法岛化身船精灵舍己救下了草帽一伙！" << std::endl;
    }
};

// ---------------------------------------------------------------------------
// Refined Abstraction: 无敌海军号
// ---------------------------------------------------------------------------
class HaiJunShip : public AbstractShip {
public:
    using AbstractShip::AbstractShip;
    std::string getName() override {
        return std::string("无敌海军号");
    }
    void feature() override {
        std::cout << getName() << " -- 船底由海楼石建造, 可以穿过无风带的巨大炮舰!" << std::endl;
    }
};
