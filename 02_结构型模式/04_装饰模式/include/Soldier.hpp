#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <utility>

// =============================================================================
// 装饰模式 (Decorator Pattern) - 海贼王主题: 黑胡子的恶魔果实
// =============================================================================
// 场景: 为黑胡子(原始组件)动态添加不同的恶魔果实能力(装饰器)，
// 每个果实能力都为其战斗方式增加新特性，且不改变黑胡子本身的战斗逻辑。

// ---------------------------------------------------------------------------
// Component (抽象组件): 战士接口
// ---------------------------------------------------------------------------
class Soldier {
public:
    virtual ~Soldier() = default;
    virtual std::string getName() const = 0;
    virtual void fight() const = 0;
};

// ---------------------------------------------------------------------------
// Concrete Component (具体组件): 黑胡子 - 马歇尔·D·蒂奇
// ---------------------------------------------------------------------------
class Teach : public Soldier {
public:
    explicit Teach(std::string n) : name(std::move(n)) {}

    std::string getName() const override { return name; }

    void fight() const override {
        std::cout << name << "依靠惊人的力量和高超的体术战斗..." << std::endl;
    }

private:
    std::string name;
};

// ---------------------------------------------------------------------------
// Decorator (抽象装饰器): 恶魔果实装饰器基类
// ---------------------------------------------------------------------------
class DevilFruitDecorator : public Soldier {
public:
    explicit DevilFruitDecorator(std::unique_ptr<Soldier> s)
        : soldier(std::move(s)) {}

    std::string getName() const override { return soldier->getName(); }

protected:
    std::unique_ptr<Soldier> soldier;
};

// ---------------------------------------------------------------------------
// Concrete Decorator: 暗暗果实
// ---------------------------------------------------------------------------
class DarkFruit : public DevilFruitDecorator {
public:
    using DevilFruitDecorator::DevilFruitDecorator;

    void fight() const override {
        soldier->fight();
        std::cout << getName()
                  << "吃了暗暗果实, 可以拥有黑洞一样的无限吸引力..." << std::endl;
        warning();
    }

private:
    void warning() const {
        std::cout << getName()
                  << "你要注意: 吃了暗暗果实, 身体元素化之后不能躲避攻击，会吸收所有伤害!" << std::endl;
    }
};

// ---------------------------------------------------------------------------
// Concrete Decorator: 震震果实
// ---------------------------------------------------------------------------
class QuakeFruit : public DevilFruitDecorator {
public:
    using DevilFruitDecorator::DevilFruitDecorator;

    void fight() const override {
        soldier->fight();
        std::cout << getName()
                  << "吃了震震果实, 可以在任意空间引发震动, 摧毁目标...!" << std::endl;
    }
};

// ---------------------------------------------------------------------------
// Concrete Decorator: 大饼果实
// ---------------------------------------------------------------------------
class PieFruit : public DevilFruitDecorator {
public:
    using DevilFruitDecorator::DevilFruitDecorator;

    void fight() const override {
        soldier->fight();
        std::cout << getName()
                  << "吃了大饼果实, 获得大饼铠甲...!" << std::endl;
        ability();
    }

private:
    void ability() const {
        std::cout << "最强辅助 -- 大饼果实可以将身边事物变成大饼, 帮助自己和队友回血..." << std::endl;
    }
};
