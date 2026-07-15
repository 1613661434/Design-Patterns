#pragma once

#include <iostream>

// =============================================================================
// 外观模式 (Facade Pattern) - 海贼王主题: 桑尼号狮吼炮系统
// =============================================================================
// 场景: 发射狮吼炮需要多个子系统协同工作(注入可乐→能量转换→目标锁定→开炮→稳定船身)。
// 外观模式将这些复杂步骤封装为简单的"瞄准"和"开炮"接口。

// ---------------------------------------------------------------------------
// Subsystem Classes: 子系统
// ---------------------------------------------------------------------------

// 可乐注入系统
class CokeSystem {
public:
    void immitCoke() {
        std::cout << "狮吼炮原料<可乐>已经注入完毕..." << std::endl;
    }
};

// 能量转换系统
class EnergySystem {
public:
    void energyConvert() {
        std::cout << "已经将所有的可乐转换为了能量..." << std::endl;
    }
};

// 目标锁定系统
class AimLockSystem {
public:
    void aimLock() {
        std::cout << "已经瞄准并且锁定了目标..." << std::endl;
    }
};

// 加农炮发射系统
class Cannon {
public:
    void cannonFire() {
        std::cout << "狮吼炮正在向目标开火..." << std::endl;
    }
};

// 风来炮稳定系统
class WindCannon {
public:
    void windCannonFire() {
        std::cout << "发射风来炮抵消后坐力稳定船身..." << std::endl;
    }
};

// ---------------------------------------------------------------------------
// Facade (外观类): 狮吼炮
// ---------------------------------------------------------------------------
// 封装5个子系统的复杂交互，对外提供简洁的"瞄准+开炮"接口。
class LionCannon {
public:
    LionCannon() {
        m_coke = new CokeSystem;
        m_energy = new EnergySystem;
        m_aimLock = new AimLockSystem;
        m_cannon = new Cannon;
        m_windCannon = new WindCannon;
    }

    ~LionCannon() {
        delete m_coke;
        delete m_energy;
        delete m_aimLock;
        delete m_cannon;
        delete m_windCannon;
    }

    // 瞄准并锁定目标 (封装3个子系统的操作)
    void aimAndLock() {
        m_coke->immitCoke();
        m_energy->energyConvert();
        m_aimLock->aimLock();
    }

    // 开炮 (封装2个子系统的操作)
    void fire() {
        m_cannon->cannonFire();
        m_windCannon->windCannonFire();
    }

private:
    CokeSystem* m_coke = nullptr;
    EnergySystem* m_energy = nullptr;
    AimLockSystem* m_aimLock = nullptr;
    Cannon* m_cannon = nullptr;
    WindCannon* m_windCannon = nullptr;
};
