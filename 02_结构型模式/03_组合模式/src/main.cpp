#include "ManagerTeam.hpp"
#include "LeafTeam.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// =============================================================================
// 构建草帽大船团的树形结构，执行战斗
// =============================================================================
void fighting() {
    vector<string> nameList = {
        "俊美海贼团", "巴托俱乐部", "八宝水军", "艾迪欧海贼团",
        "咚塔塔海贼团", "巨兵海贼团", "约塔玛利亚大船团"
    };

    // 根节点: 草帽海贼团 (组合节点)
    ManagerTeam* root = new ManagerTeam("草帽海贼团");

    for (size_t i = 0; i < nameList.size(); ++i) {
        ManagerTeam* child = new ManagerTeam(nameList.at(i));
        root->add(child);

        if (i == nameList.size() - 1) {
            // 给最后一个番队添加9个子船队(叶子节点)
            for (int j = 0; j < 9; ++j) {
                LeafTeam* leaf = new LeafTeam("第" + to_string(j + 1) + "番队");
                child->add(leaf);
                leaf->fight();
                leaf->display();
            }
            child->fight();
            child->display();
        }
    }

    root->fight();
    root->display();

    cout << "====================================" << endl;

    // 递归释放所有节点
    gameover(root);
}

int main() {
    fighting();
    return 0;
}
