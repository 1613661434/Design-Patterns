#include "State.hpp"
#include "Sanji.hpp"
#include <iostream>
#include <vector>

// ============ 状态 working() 实现 ============

void ForenoonState::working(Sanji* sanji)
{
    int time = sanji->getClock();
    if (time < 8)
    {
        std::cout << "当前时间<" << time << ">点, 准备早餐, 布鲁克得多喝点牛奶..." << std::endl;
    }
    else if (time > 8 && time < 11)
    {
        std::cout << "当前时间<" << time << ">点, 去船头钓鱼, 储备食材..." << std::endl;
    }
    else
    {
        sanji->setState(new NoonState);
        sanji->working();
    }
}

void NoonState::working(Sanji* sanji)
{
    int time = sanji->getClock();
    if (time < 13)
    {
        std::cout << "当前时间<" << time << ">点, 去厨房做午饭, 给路飞多做点肉..." << std::endl;
    }
    else
    {
        sanji->setState(new AfternoonState);
        sanji->working();
    }
}

void AfternoonState::working(Sanji* sanji)
{
    int time = sanji->getClock();
    if (time < 15)
    {
        std::cout << "当前时间<" << time << ">点, 准备下午茶, 给罗宾和娜美制作爱心甜点..." << std::endl;
    }
    else if (time > 15 && time < 18)
    {
        std::cout << "当前时间<" << time << ">点, 和乔巴去船尾钓鱼, 储备食材..." << std::endl;
    }
    else
    {
        sanji->setState(new EveningState);
        sanji->working();
    }
}

void EveningState::working(Sanji* sanji)
{
    int time = sanji->getClock();
    if (time < 19)
    {
        std::cout << "当前时间<" << time << ">点, 去厨房做晚饭, 让索隆多喝点汤..." << std::endl;
    }
    else
    {
        std::cout << "当前时间<" << time << ">点, 今天过得很高兴, 累了睡觉了..." << std::endl;
    }
}

// ============ main ============

int main()
{
    Sanji* sanji = new Sanji;
    // 时间点
    std::vector<int> data{ 7, 10, 12, 14, 16, 18, 22 };
    for (const auto& item : data)
    {
        sanji->setClock(item);
        sanji->working();
    }
    delete sanji;

    return 0;
}
