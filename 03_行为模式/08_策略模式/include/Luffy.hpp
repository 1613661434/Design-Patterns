#pragma once

#include "Strategy.hpp"

// 难度级别
enum class Level : char { Easy, Normal, Hard, Experts, Professional };

// 路飞 - 上下文
class Luffy
{
public:
    void fight(Level level, bool isfar = false)
    {
        if (m_strategy)
        {
            delete m_strategy;
            m_strategy = nullptr;
        }
        switch (level)
        {
        case Level::Easy:
            m_strategy = new YiDang;
            break;
        case Level::Normal:
            m_strategy = new ErDang;
            break;
        case Level::Hard:
            m_strategy = new SanDang;
            break;
        case Level::Experts:
            m_strategy = new SiDang;
            break;
        case Level::Professional:
            m_strategy = new WuDang;
            break;
        default:
            break;
        }
        m_strategy->fight(isfar);
    }
    ~Luffy()
    {
        delete m_strategy;
    }
private:
    AbstractStrategy* m_strategy = nullptr;
};
