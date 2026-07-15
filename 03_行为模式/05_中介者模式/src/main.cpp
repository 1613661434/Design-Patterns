#include "MediatorOrg.hpp"
#include "Country.hpp"
#include "WorldGovt.hpp"
#include "GeMingArmy.hpp"
#include "Alabasta.hpp"
#include "Dressrosa.hpp"
#include "Lulusia.hpp"
#include "Kamabaka.hpp"
#include <iostream>

// ============ MediatorOrg 成员函数实现 ============

void MediatorOrg::addMember(Country* country)
{
    m_countryMap.insert(std::make_pair(country->getName(), country));
}

// ============ WorldGovt 成员函数实现 ============

void WorldGovt::declare(std::string msg, Country* country, std::string name)
{
    if (m_countryMap.find(name) != m_countryMap.end())
    {
        std::string str = msg + "【来自: " + country->getName() + "】";
        m_countryMap[name]->setMessage(str);
    }
}

// ============ GeMingArmy 成员函数实现 ============

void GeMingArmy::declare(std::string msg, Country* country, std::string /*name*/)
{
    std::string str = msg + "【来自: " + country->getName() + "】";
    for (const auto& item : m_countryMap)
    {
        if (item.second == country)
        {
            continue;
        }
        item.second->setMessage(str);
    }
}

// ============ Alabasta 成员函数实现 ============

void Alabasta::declare(std::string msg, std::string country)
{
    m_mediator->declare(msg, this, country);
}

void Alabasta::setMessage(std::string msg)
{
    std::cout << "阿拉巴斯坦得到的消息: " << msg << std::endl;
}

std::string Alabasta::getName()
{
    return "阿拉巴斯坦";
}

// ============ Dressrosa 成员函数实现 ============

void Dressrosa::declare(std::string msg, std::string country)
{
    m_mediator->declare(msg, this, country);
}

void Dressrosa::setMessage(std::string msg)
{
    std::cout << "德雷斯罗萨得到的消息: " << msg << std::endl;
}

std::string Dressrosa::getName()
{
    return "德雷斯罗萨";
}

// ============ Lulusia 成员函数实现 ============

void Lulusia::declare(std::string msg, std::string country)
{
    m_mediator->declare(msg, this, country);
}

void Lulusia::setMessage(std::string msg)
{
    std::cout << "露露西亚得到的消息: " << msg << std::endl;
}

std::string Lulusia::getName()
{
    return "露露西亚";
}

// ============ Kamabaka 成员函数实现 ============

void Kamabaka::declare(std::string msg, std::string country)
{
    m_mediator->declare(msg, this, country);
}

void Kamabaka::setMessage(std::string msg)
{
    std::cout << "卡玛巴卡得到的消息: " << msg << std::endl;
}

std::string Kamabaka::getName()
{
    return "卡玛巴卡";
}

// ============ main ============

int main()
{
    // 世界政府
    WorldGovt* world = new WorldGovt;
    Alabasta* alaba = new Alabasta(world);
    Dressrosa* dresa = new Dressrosa(world);
    // 世界政府添加成员
    world->addMember(alaba);
    world->addMember(dresa);
    // 世界政府成员发声
    alaba->declare("德雷斯罗萨倒卖军火, 搞得我国连年打仗, 必须给个说法!!!", dresa->getName());
    dresa->declare("天龙人都和我多弗朗明哥做生意, 你算老几, 呸!!!", alaba->getName());
    std::cout << "======================================" << std::endl;
    // 革命军
    GeMingArmy* geming = new GeMingArmy;
    Lulusia* lulu = new Lulusia(geming);
    Kamabaka* kama = new Kamabaka(geming);
    geming->addMember(lulu);
    geming->addMember(kama);
    lulu->declare("我草, 我的国家被伊姆毁灭了!!!", lulu->getName());

    delete world;
    delete alaba;
    delete dresa;
    delete geming;
    delete lulu;
    delete kama;
    return 0;
}
