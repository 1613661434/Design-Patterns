#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

// ============================================================================
// 建造者模式 - 产品类 (Product)
// 被构建的复杂对象
// ============================================================================

// ============================================================================
// 产品: 桑尼号 (SunnyShip)
// 使用 vector 存储零件列表
// ============================================================================
class SunnyShip
{
public:
    // 添加零件
    void addParts(std::string name)
    {
        m_parts.push_back(name);
    }

    // 展示所有零件
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            std::cout << item << "   ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<std::string> m_parts;
};

// ============================================================================
// 产品: 梅利号 (MerryShip)
// 使用 map 存储零件名称与描述
// ============================================================================
class MerryShip
{
public:
    // 组装
    void assemble(std::string name, std::string parts)
    {
        m_parts.insert(std::make_pair(name, parts));
    }

    // 展示所有零件
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            std::cout << item.first << ": " << item.second << "  ";
        }
        std::cout << std::endl;
    }

private:
    std::map<std::string, std::string> m_parts;
};
