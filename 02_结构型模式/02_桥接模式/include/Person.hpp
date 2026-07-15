#pragma once

#include <string>
#include <iostream>

// =============================================================================
// 桥接模式 - 数据类: 人员信息
// =============================================================================
// 这是桥接模式中使用的数据类，存储船员的基本信息。
// 作为独立的 header 以保持代码组织清晰。

struct Person {
    Person(std::string name, std::string job, std::string ability, std::string reward, std::string biezhu = std::string())
        : name(std::move(name))
        , job(std::move(job))
        , ability(std::move(ability))
        , reward(std::move(reward))
        , beiZhu(std::move(biezhu))
    {}

    ~Person() {
        std::cout << name << "被析构..." << std::endl;
    }

    std::string name;    // 名字
    std::string job;     // 职责
    std::string ability; // 能力
    std::string reward;  // 赏金
    std::string beiZhu;  // 备注
};
