#pragma once

#include <list>
#include <vector>
#include <string>
#include <iostream>

#include "AbstractTeam.hpp"

// =============================================================================
// 组合模式 - Composite (组合节点): 管理团队
// =============================================================================
// 组合节点包含子节点（叶子或组合），实现管理子节点的逻辑。

class ManagerTeam : public AbstractTeam {
public:
    using AbstractTeam::AbstractTeam;

    void fight() override {
        std::cout << m_name + "和黑胡子的恶魔果实能力者战斗!!!" << std::endl;
    }

    void add(AbstractTeam* node) override {
        node->setParent(this);
        m_children.push_back(node);
    }

    void remove(AbstractTeam* node) override {
        node->setParent(nullptr);
        m_children.remove(node);
    }

    bool hasChild() override {
        return true;
    }

    std::list<AbstractTeam*> getChildren() const {
        return m_children;
    }

    void display() override {
        std::string info;
        for (const auto item : m_children) {
            if (item == m_children.back()) {
                info += item->getName();
            } else {
                info += item->getName() + ", ";
            }
        }
        std::cout << m_name + "的船队是【" << info << "】" << std::endl;
    }

    ~ManagerTeam() override {
        std::cout << "我是【" << m_name << "】战斗结束, 拜拜..." << std::endl;
    }

private:
    std::list<AbstractTeam*> m_children;
};

// ---------------------------------------------------------------------------
// 辅助: 递归释放树形内存
// ---------------------------------------------------------------------------
inline void gameover(AbstractTeam* root) {
    if (root == nullptr) {
        return;
    }
    if (root->hasChild()) {
        ManagerTeam* team = dynamic_cast<ManagerTeam*>(root);
        std::list<AbstractTeam*> children = team->getChildren();
        for (const auto item : children) {
            gameover(item);
        }
    }
    delete root;
}
