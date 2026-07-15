#include "../include/Prototype.hpp"
using namespace std;

// ============================================================================
// 原型模式演示
// 通过 clone() 方法复制已有士兵对象来创建新士兵，无需重新初始化。
// 这在对象创建成本高的场景下特别有用。
// ============================================================================
int main()
{
    cout << "========== 原型模式 - 杰尔马超级士兵克隆 ==========\n" << endl;

    // 创建一个 Soldier66 原型，并克隆
    GermaSoldier* obj = new Soldier66;
    GermaSoldier* soldier = obj->clone();
    cout << soldier->whoAmI() << endl;
    delete soldier;
    delete obj;

    // 创建一个 Soldier67 原型，并克隆
    obj = new Soldier67;
    soldier = obj->clone();
    cout << soldier->whoAmI() << endl;
    delete soldier;
    delete obj;

    return 0;
}
