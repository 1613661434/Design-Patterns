#pragma once

#include <iostream>
#include <string>
#include <map>
#include <utility>

#include "Person.hpp"

// =============================================================================
// 桥接模式 - Implementor (实现接口): 抽象团队
// =============================================================================
// 定义"团队"的实现接口。桥接模式中，AbstractTeam作为Implementor，
// 与Abstraction (AbstractShip) 通过组合关联，两者可以独立变化。

class AbstractTeam {
public:
    explicit AbstractTeam(std::string name) : m_teamName(std::move(name)) {}

    std::string getTeamName() const {
        return m_teamName;
    }

    void addMember(Person* p) {
        m_infoMap.insert(std::make_pair(p->name, p));
    }

    void show() const {
        std::cout << m_teamName << ": " << std::endl;
        for (const auto& item : m_infoMap) {
            std::cout << "【Name: " << item.second->name
                      << ", Job: " << item.second->job
                      << ", Ability: " << item.second->ability
                      << ", MoneyReward: " << item.second->reward
                      << ", BeiZhu: " << item.second->beiZhu
                      << "】" << std::endl;
        }
    }

    virtual void executeTask() = 0;   // 执行任务

    virtual ~AbstractTeam() {
        for (const auto& item : m_infoMap) {
            delete item.second;
        }
    }

protected:
    std::string m_teamName;
    std::map<std::string, Person*> m_infoMap;
};

// ---------------------------------------------------------------------------
// Concrete Implementor: 草帽海贼团
// ---------------------------------------------------------------------------
class CaoMaoTeam : public AbstractTeam {
public:
    using AbstractTeam::AbstractTeam;
    void executeTask() override {
        std::cout << "在海上冒险，找到 ONE PIECE 成为海贼王！" << std::endl;
    }
};

// ---------------------------------------------------------------------------
// Concrete Implementor: 斯摩格部队
// ---------------------------------------------------------------------------
class SmokerTeam : public AbstractTeam {
public:
    using AbstractTeam::AbstractTeam;
    void executeTask() override {
        std::cout << "为了正义, 先将草帽一伙一网打尽!!!" << std::endl;
    }
};
