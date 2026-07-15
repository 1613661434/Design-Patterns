#include "LionCannon.hpp"
#include <iostream>
using namespace std;

int main() {
    // 客户端通过外观接口操作, 无需了解5个子系统的复杂协作
    LionCannon* lion = new LionCannon;
    lion->aimAndLock();   // 瞄准: 内部执行 注入可乐→能量转换→目标锁定
    lion->fire();         // 开炮: 内部执行 狮吼炮发射→风来炮稳定

    delete lion;
    return 0;
}
