#include "Luffy.hpp"
#include <iostream>

int main()
{
    Luffy* luffy = new Luffy;
    std::cout << "--- 在香波地群岛遇到了海军士兵: " << std::endl;
    luffy->fight(Level::Easy);
    std::cout << "--- 在魔谷镇遇到了贝拉米: " << std::endl;
    luffy->fight(Level::Normal);
    std::cout << "--- 在司法岛遇到了罗布·路奇: " << std::endl;
    luffy->fight(Level::Hard);
    std::cout << "--- 在德雷斯罗萨遇到了多弗朗明哥: " << std::endl;
    luffy->fight(Level::Experts);
    std::cout << "--- 在鬼岛遇到了凯多: " << std::endl;
    luffy->fight(Level::Professional);

    delete luffy;
    return 0;
}
