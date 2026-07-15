#pragma once

#include <string>
#include <iostream>

// =============================================================================
// 享元模式 - Flyweight (抽象享元基类)
// =============================================================================
// 定义所有享元对象的公共接口。包含内部状态(精灵图、颜色)和外部状态接口。

class FlyweightBody {
public:
    explicit FlyweightBody(std::string sprite) : m_sprite(std::move(sprite)) {}

    virtual void move(int x, int y, int speed) = 0;
    virtual void draw(int x, int y) = 0;
    virtual ~FlyweightBody() {}

protected:
    std::string m_sprite;                    // 精灵图片 (内部状态)
    std::string m_color = std::string("black"); // 渲染颜色 (内部状态)
};
