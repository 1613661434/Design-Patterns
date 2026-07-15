#pragma once

#include <string>
#include <iostream>

// =============================================================================
// 组合模式 - Component (抽象节点): 团队抽象
// =============================================================================
// 定义叶子节点和组合节点的公共接口，使客户端可以一致地处理单个对象和组合对象。

class AbstractTeam {
public:
    explicit AbstractTeam(std::string name) : m_name(std::move(name)) {}

    void setParent(AbstractTeam* node) {
        m_parent = node;
    }
    AbstractTeam* getParent() const {
        return m_parent;
    }
    std::string getName() const {
        return m_name;
    }

    virtual bool hasChild() {
        return false;
    }
    virtual void add(AbstractTeam* /*node*/) {}
    virtual void remove(AbstractTeam* /*node*/) {}

    virtual void fight() = 0;
    virtual void display() = 0;

    virtual ~AbstractTeam() {}

protected:
    std::string m_name;
    AbstractTeam* m_parent = nullptr;
};
