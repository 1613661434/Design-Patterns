#include "../include/FactoryMethod.hpp"
using namespace std;

// ============================================================================
// 工厂方法模式演示
// 每种产品都有对应的专门工厂类，遵循开闭原则。
// 新增产品时只需新增产品类和对应的工厂类，无需修改已有代码。
// ============================================================================
int main()
{
    cout << "========== 工厂方法模式 - 恶魔果实工厂 ==========" << endl;

    // 使用蝙蝠工厂创建蝙蝠果实能力者
    AbstractFactory* factory = new BatFactory;
    AbstractSmile* obj = factory->createSmile();
    obj->transform();
    obj->ability();
    delete obj;
    delete factory;

    // 使用狮子工厂创建狮子果实能力者
    factory = new LionFactory;
    obj = factory->createSmile();
    obj->transform();
    obj->ability();
    delete obj;
    delete factory;

    // 使用绵羊工厂创建绵羊果实能力者
    factory = new SheepFactory;
    obj = factory->createSmile();
    obj->transform();
    obj->ability();
    delete obj;
    delete factory;

    return 0;
}
