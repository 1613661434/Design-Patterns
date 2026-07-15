#include "BombBodyFactory.hpp"
#include "UniqueBomb.hpp"
#include "LaunchBomb.hpp"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // =========================================================================
    // 场景: 批量发射炸弹
    // 同名炸弹共享弹体(内部状态), 位置和速度各自独立(外部状态)
    // =========================================================================
    BombBodyFactory* factory = new BombBodyFactory;
    vector<LaunchBomb*> ballList;
    vector<string> namelist = {
        "撒旦-1", "撒旦-1",   // 这两个共享 "撒旦-1" 弹体
        "撒旦-2", "撒旦-2", "撒旦-2", // 这三个共享 "撒旦-2" 弹体
        "撒旦-3"              // 创建 "撒旦-3" 弹体
    };

    for (const auto& name : namelist) {
        int x = 0, y = 0;
        LaunchBomb* ball = new LaunchBomb(factory->getSharedData(name));
        for (int i = 0; i < 3; ++i) {
            x += rand() % 100;
            y += rand() % 50;
            ball->move(x, y);
        }
        cout << "=========================" << endl;
        ballList.push_back(ball);
    }

    // =========================================================================
    // 彩蛋 (唯一享元, 不共享)
    // =========================================================================
    UniqueBomb* unique = new UniqueBomb("大彩蛋");
    LaunchBomb* bomb = new LaunchBomb(unique);
    int x = 0, y = 0;
    for (int i = 0; i < 3; ++i) {
        x += rand() % 100;
        y += rand() % 50;
        bomb->move(x, y);
    }

    // =========================================================================
    // 资源释放
    // =========================================================================
    cout << "================== 资源释放 ==================" << endl;
    for (auto ball : ballList) {
        delete ball;
    }
    delete factory;   // 释放所有共享弹体
    delete unique;    // 释放彩蛋弹体
    delete bomb;      // 释放彩蛋发射器

    return 0;
}
