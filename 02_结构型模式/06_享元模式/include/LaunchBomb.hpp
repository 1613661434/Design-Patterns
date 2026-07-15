#pragma once

#include "FlyweightBody.hpp"

// =============================================================================
// 享元模式 - Client (客户端类): 发射炸弹
// =============================================================================
// 持有享元对象的引用，并维护对象的外部状态(位置、速度)。
// 外部状态随每个对象而变化，不需要共享。

class LaunchBomb {
public:
    explicit LaunchBomb(FlyweightBody* body) : m_bomb(body) {}

    int getX() const { return m_x; }
    int getY() const { return m_y; }

    void setSpeed(int speed) { m_speed = speed; }
    int getSpeed() const { return m_speed; }

    void move(int x, int y) {
        m_x = x;
        m_y = y;
        m_bomb->move(m_x, m_y, m_speed);
        draw();
    }

    void draw() {
        m_bomb->draw(m_x, m_y);
    }

private:
    int m_x = 0;                       // 外部状态: X坐标
    int m_y = 0;                       // 外部状态: Y坐标
    int m_speed = 100;                 // 外部状态: 速度
    FlyweightBody* m_bomb = nullptr;   // 共享的内部状态引用
};
