#include "Observer.hpp"
#include "ConcreteNews.hpp"
#include "ConcreteObserver.hpp"
#include <iostream>

// ============ NewsAgency 成员函数实现 ============

void NewsAgency::attach(Observer* ob)
{
    m_list.push_back(ob);
}

void NewsAgency::deatch(Observer* ob)
{
    m_list.remove(ob);
}

// ============ Morgans 成员函数实现 ============

void Morgans::notify(std::string msg)
{
    std::cout << "摩根斯新闻社报纸的订阅者一共有<" << m_list.size() << ">人" << std::endl;
    for (const auto& item : m_list)
    {
        item->update(msg);
    }
}

// ============ Gossip 成员函数实现 ============

void Gossip::notify(std::string msg)
{
    std::cout << "八卦新闻社报纸的订阅者一共有<" << m_list.size() << ">人" << std::endl;
    for (const auto& item : m_list)
    {
        item->update(msg);
    }
}

// ============ Dragon 成员函数实现 ============

void Dragon::update(std::string msg)
{
    std::cout << "@@@路飞的老爸革命军龙收到消息: " << msg << std::endl;
}

// ============ Shanks 成员函数实现 ============

void Shanks::update(std::string msg)
{
    std::cout << "@@@路飞的引路人红发香克斯收到消息: " << msg << std::endl;
}

// ============ Bartolomeo 成员函数实现 ============

void Bartolomeo::update(std::string msg)
{
    std::cout << "@@@路飞的头号粉丝巴托洛米奥收到消息: " << msg << std::endl;
}

// ============ main ============

int main()
{
    Morgans* ms = new Morgans;
    Gossip* gossip = new Gossip;
    Dragon* dragon = new Dragon("蒙奇·D·龙", ms);
    Shanks* shanks = new Shanks("香克斯", ms);
    Bartolomeo* barto = new Bartolomeo("巴托洛米奥", gossip);
    ms->notify("蒙奇·D·路飞成为新世界的新的四皇之一, 赏金30亿贝里!!!");
    std::cout << "======================================" << std::endl;
    gossip->notify("女帝汉库克想要嫁给路飞, 给路飞生猴子, 哈哈哈...");

    delete ms;
    delete gossip;
    delete dragon;
    delete shanks;
    delete barto;

    return 0;
}
