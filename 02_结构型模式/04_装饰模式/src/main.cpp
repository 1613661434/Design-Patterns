#include "Soldier.hpp"
#include <memory>
#include <iostream>
using namespace std;

int main() {
    // 创建黑胡子 (原始组件)
    unique_ptr<Soldier> teach = make_unique<Teach>("马歇尔·D·蒂奇");

    // 动态添加恶魔果实能力 (装饰器模式 - 层层包装)
    teach = make_unique<DarkFruit>(move(teach));    // 暗暗果实
    teach = make_unique<QuakeFruit>(move(teach));   // 震震果实
    teach = make_unique<PieFruit>(move(teach));     // 大饼果实

    // 展示所有能力 (从最外层开始调用, 递归触发内层)
    teach->fight();

    // 智能指针自动管理内存, 无需手动delete
    return 0;
}
