#pragma once

#include "FlyweightBody.hpp"

// =============================================================================
// 享元模式 - Unique Flyweight (唯一享元): 彩蛋炸弹
// =============================================================================
// 无需共享的特殊享元对象，每个都是唯一的实例。

class UniqueBomb : public FlyweightBody {
public:
    using FlyweightBody::FlyweightBody;

    void move(int x, int y, int speed) override {
        (void)x;
        (void)y;
        (void)speed;
        std::cout << "彩蛋在往指定位置移动, 准备爆炸发放奖励..." << std::endl;
    }

    void draw(int x, int y) override {
        std::cout << "在 (" << x << ", " << y << ") 的位置重绘彩蛋运动轨迹..." << std::endl;
    }
};
