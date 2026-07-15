#pragma once

#include <string>
#include <map>
#include <iostream>

#include "SharedBombBody.hpp"

// =============================================================================
// 享元模式 - Flyweight Factory (享元工厂)
// =============================================================================
// 管理享元对象的创建和共享。当客户端请求同名炸弹弹体时，若已存在则直接返回
// (共享)，否则创建新的并缓存到内部容器中。

class BombBodyFactory {
public:
    SharedBombBody* getSharedData(const std::string& name) {
        SharedBombBody* data = nullptr;

        // 遍历容器查找是否已存在
        for (const auto& item : m_bodyMap) {
            if (item.first == name) {
                data = item.second;
                std::cout << "正在复用 <" << name << ">..." << std::endl;
                break;
            }
        }

        // 未找到，创建新的并缓存
        if (data == nullptr) {
            data = new SharedBombBody(name);
            std::cout << "正在创建 <" << name << ">..." << std::endl;
            m_bodyMap.insert(std::make_pair(name, data));
        }
        return data;
    }

    ~BombBodyFactory() {
        for (auto& item : m_bodyMap) {
            delete item.second;
        }
    }

private:
    std::map<std::string, SharedBombBody*> m_bodyMap;
};
