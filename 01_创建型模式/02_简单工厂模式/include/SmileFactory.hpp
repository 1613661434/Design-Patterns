#pragma once

#include <iostream>
#include <string>

// ============================================================================
// 简单工厂模式 (Simple Factory Pattern)
//
// 注意：简单工厂模式不属于 GoF 23种设计模式，但非常常用
//
// 抽象产品类：恶魔果实能力者接口
// ============================================================================
class AbstractSmile
{
public:
    virtual void transform() {}
    virtual void ability() {}
    virtual ~AbstractSmile() = default;
};

// ============================================================================
// 具体产品类：人造恶魔果实·绵羊形态
// ============================================================================
class SheepSmile : public AbstractSmile
{
public:
    void transform() override
    {
        std::cout << "变成人兽 -- 山羊人形态..." << std::endl;
    }
    void ability() override
    {
        std::cout << "将手臂变成绵羊角的招式 -- 巨羊角" << std::endl;
    }
};

// ============================================================================
// 具体产品类：人造恶魔果实·狮子形态
// ============================================================================
class LionSmile : public AbstractSmile
{
public:
    void transform() override
    {
        std::cout << "变成人兽 -- 狮子人形态..." << std::endl;
    }
    void ability() override
    {
        std::cout << "火遁·豪火球之术..." << std::endl;
    }
};

// ============================================================================
// 具体产品类：人造恶魔果实·蝙蝠形态
// ============================================================================
class BatSmile : public AbstractSmile
{
public:
    void transform() override
    {
        std::cout << "变成人兽 -- 蝙蝠人形态..." << std::endl;
    }
    void ability() override
    {
        std::cout << "声纳引箭之万剑归宗..." << std::endl;
    }
};

// ============================================================================
// 产品类型枚举
// ============================================================================
enum class Type : char { SHEEP, LION, BAT };

// ============================================================================
// 工厂类：恶魔果实工厂
// 根据参数类型创建对应的产品对象
// ============================================================================
class SmileFactory
{
public:
    SmileFactory() = default;
    ~SmileFactory() = default;

    AbstractSmile* createSmile(Type type)
    {
        AbstractSmile* ptr = nullptr;
        switch (type)
        {
        case Type::SHEEP:
            ptr = new SheepSmile;
            break;
        case Type::LION:
            ptr = new LionSmile;
            break;
        case Type::BAT:
            ptr = new BatSmile;
            break;
        default:
            break;
        }
        return ptr;
    }
};
