#include "../include/SmileFactory.hpp"
using namespace std;

// ============================================================================
// 简单工厂模式演示
// 通过 SmileFactory 工厂类根据枚举类型创建不同的恶魔果实能力者
// 客户端只需要知道产品类型参数，无需直接实例化具体产品类
// ============================================================================
int main()
{
    SmileFactory* factory = new SmileFactory;

    cout << "========== 简单工厂模式 - 恶魔果实工厂 ==========" << endl;

    // 生产蝙蝠果实能力者
    AbstractSmile* obj = factory->createSmile(Type::BAT);
    obj->transform();
    obj->ability();
    delete obj;

    // 生产狮子果实能力者
    obj = factory->createSmile(Type::LION);
    obj->transform();
    obj->ability();
    delete obj;

    // 生产绵羊果实能力者
    obj = factory->createSmile(Type::SHEEP);
    obj->transform();
    obj->ability();
    delete obj;

    delete factory;
    return 0;
}
