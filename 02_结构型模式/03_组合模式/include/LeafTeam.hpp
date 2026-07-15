#pragma once

#include "AbstractTeam.hpp"

// =============================================================================
// 组合模式 - Leaf (叶子节点): 番队
// =============================================================================
// 叶子节点没有子节点，实现抽象节点的接口，代表树形结构中最小的作战单元。

class LeafTeam : public AbstractTeam {
public:
    using AbstractTeam::AbstractTeam;

    void fight() override {
        std::cout << m_parent->getName() + m_name + "与黑胡子的船员进行近距离肉搏战..." << std::endl;
    }
    void display() override {
        std::cout << "我是" << m_parent->getName() << "下属的" << m_name << std::endl;
    }
    ~LeafTeam() override {
        std::cout << "我是" << m_parent->getName() << "下属的" << m_name
                  << ", 战斗已经结束, 拜拜..." << std::endl;
    }
};
