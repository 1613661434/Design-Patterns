#include "../include/Ships.hpp"
#include "../include/ShipBuilder.hpp"
#include "../include/SunnyBuilder.hpp"
#include "../include/MerryBuilder.hpp"
#include "../include/Director.hpp"
using namespace std;

// ============================================================================
// 建造桑尼号
// 使用导演类 + 桑尼建造者，分别构建简约型、标准型、豪华型桑尼号
// ============================================================================
void buildSunny()
{
    Director* director = new Director;
    SunnyBuilder* builder = new SunnyBuilder;

    // 简约型
    director->setBuilder(builder);
    director->buildSimpleShip();
    SunnyShip* sunny = builder->getSunny();
    cout << "桑尼号 [简约型]: ";
    sunny->showParts();
    delete sunny;

    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->buildStandardShip();
    sunny = builder->getSunny();
    cout << "桑尼号 [标准型]: ";
    sunny->showParts();
    delete sunny;

    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->buildRegalShip();
    sunny = builder->getSunny();
    cout << "桑尼号 [豪华型]: ";
    sunny->showParts();
    delete sunny;

    delete builder;
    delete director;
}

// ============================================================================
// 建造梅利号
// 使用导演类 + 梅利建造者，分别构建简约型、标准型、豪华型梅利号
// ============================================================================
void buildMerry()
{
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;

    // 简约型
    director->setBuilder(builder);
    director->buildSimpleShip();
    MerryShip* merry = builder->getMerry();
    cout << "梅利号 [简约型]: ";
    merry->showParts();
    delete merry;

    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->buildStandardShip();
    merry = builder->getMerry();
    cout << "梅利号 [标准型]: ";
    merry->showParts();
    delete merry;

    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->buildRegalShip();
    merry = builder->getMerry();
    cout << "梅利号 [豪华型]: ";
    merry->showParts();
    delete merry;

    delete builder;
    delete director;
}

// ============================================================================
// 建造者模式演示
// 桑尼号和梅利号各有三种配置等级 (简约型/标准型/豪华型)
// 导演类统一管理构建流程，建造者各自实现构建细节
// ============================================================================
int main()
{
    cout << "========== 建造者模式 - 船只建造系统 ==========\n" << endl;

    buildSunny();
    cout << "=====================================" << endl;
    buildMerry();

    return 0;
}
