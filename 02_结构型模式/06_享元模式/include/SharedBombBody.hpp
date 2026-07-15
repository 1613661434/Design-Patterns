#pragma once

#include "FlyweightBody.hpp"

// =============================================================================
// 享元模式 - Concrete Flyweight (具体共享享元): 炸弹弹体
// =============================================================================
// 包含可共享的内部状态(精灵图、颜色)，所有相同类型的炸弹共享这些数据。

class SharedBombBody : public FlyweightBody {
public:
    using FlyweightBody::FlyweightBody;

    void move(int x, int y, int speed) override {
        std::cout << "炸弹以每小时" << speed << "速度飞到了("
                  << x << ", " << y << ") 的位置..." << std::endl;
    }

    void draw(int x, int y) override {
        std::cout << "在 (" << x << ", " << y << ") 的位置重绘炸弹弹体..." << std::endl;
    }
};
