#pragma once

#include <iostream>

// 抽象的策略类
class AbstractStrategy
{
public:
    virtual void fight(bool isfar = false) = 0;
    virtual ~AbstractStrategy() {}
};

// 一档
class YiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        std::cout << "*** 现在使用的是一档: ";
        if (isfar)
        {
            std::cout << "橡胶机关枪" << std::endl;
        }
        else
        {
            std::cout << "橡胶·攻城炮" << std::endl;
        }
    }
};

// 二挡
class ErDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        std::cout << "*** 切换成二挡: ";
        if (isfar)
        {
            std::cout << "橡胶Jet火箭" << std::endl;
        }
        else
        {
            std::cout << "橡胶Jet·铳乱打" << std::endl;
        }
    }
};

// 三挡
class SanDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        std::cout << "*** 切换成三挡: ";
        if (isfar)
        {
            std::cout << "橡胶巨人回旋弹" << std::endl;
        }
        else
        {
            std::cout << "橡胶巨人战斧" << std::endl;
        }
    }
};

// 四挡
class SiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        std::cout << "*** 切换成四挡: ";
        if (isfar)
        {
            std::cout << "橡胶狮子火箭炮" << std::endl;
        }
        else
        {
            std::cout << "橡胶犀牛榴弹炮" << std::endl;
        }
    }
};

// 五档
class WuDang : public AbstractStrategy
{
public:
    void fight(bool /*isfar*/ = false) override
    {
        std::cout << "*** 切换成五挡: 变成尼卡形态可以把物体变成橡胶, 并任意改变物体的形态对其进行攻击!!!" << std::endl;
    }
};
