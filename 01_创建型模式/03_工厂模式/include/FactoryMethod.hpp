#pragma once

#include <iostream>
#include <string>

// ============================================================================
// 工厂方法模式 (Factory Method Pattern)
// GoF 定义: 定义一个创建对象的接口，但让子类决定实例化哪个类。
//           工厂方法将对象的创建延迟到子类。
// ============================================================================

// 抽象产品类：恶魔果实能力者接口 (纯虚函数)
class AbstractSmile
{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
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
// 抽象工厂类：定义创建产品的抽象方法
// ============================================================================
class AbstractFactory
{
public:
    virtual AbstractSmile* createSmile() = 0;
    virtual ~AbstractFactory() = default;
};

// ============================================================================
// 具体工厂类：绵羊果实工厂
// ============================================================================
class SheepFactory : public AbstractFactory
{
public:
    AbstractSmile* createSmile() override
    {
        return new SheepSmile;
    }
    ~SheepFactory()
    {
        std::cout << "释放 SheepFactory 类相关的内存资源" << std::endl;
    }
};

// ============================================================================
// 具体工厂类：狮子果实工厂
// ============================================================================
class LionFactory : public AbstractFactory
{
public:
    AbstractSmile* createSmile() override
    {
        return new LionSmile;
    }
    ~LionFactory()
    {
        std::cout << "释放 LionFactory 类相关的内存资源" << std::endl;
    }
};

// ============================================================================
// 具体工厂类：蝙蝠果实工厂
// ============================================================================
class BatFactory : public AbstractFactory
{
public:
    AbstractSmile* createSmile() override
    {
        return new BatSmile;
    }
    ~BatFactory()
    {
        std::cout << "释放 BatFactory 类相关的内存资源" << std::endl;
    }
};
