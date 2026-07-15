#include "../include/AbstractFactory.hpp"
using namespace std;

// ============================================================================
// 抽象工厂模式演示
// 不同等级的工厂可以生产不同配置的战船。
// 每艘战船包含三个产品族：船体(ShipBody)、武器(Weapon)、动力(Engine)。
// 客户端通过抽象工厂接口操作，无需知道具体产品类。
// ============================================================================
int main()
{
    cout << "========== 抽象工厂模式 - 战船生产系统 ==========\n" << endl;

    // 基础型战船: 木材 + 枪 + 人力
    cout << ">> 生产基础型战船:" << endl;
    AbstractFactory* factory = new BasicFactory;
    Ship* ship = factory->createShip();
    cout << ship->getProperty() << endl;
    delete ship;
    delete factory;

    cout << endl;

    // 标准型战船: 钢铁 + 机关炮 + 内燃机
    cout << ">> 生产标准型战船:" << endl;
    factory = new StandardFactory;
    ship = factory->createShip();
    cout << ship->getProperty() << endl;
    delete ship;
    delete factory;

    cout << endl;

    // 旗舰型战船: 合金 + 激光 + 核能
    cout << ">> 生产旗舰型战船:" << endl;
    factory = new UltimateFactory;
    ship = factory->createShip();
    cout << ship->getProperty() << endl;
    delete ship;
    delete factory;

    return 0;
}
