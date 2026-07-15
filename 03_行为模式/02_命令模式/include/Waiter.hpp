#pragma once

#include <iostream>
#include <string>
#include <list>
#include <map>
#include "Command.hpp"

// 服务员路飞 - 命令的调用者
class WaiterLuffy
{
public:
    // 下单
    void setOrder(int index, AbstractCommand* cmd)
    {
        std::cout << index << "号桌点了" << cmd->name() << std::endl;
        if (cmd->name() == "鱼香肉丝")
        {
            std::cout << "没有鱼了, 做不了鱼香肉丝, 点个别的菜吧..." << std::endl;
            return;
        }
        // 没找到该顾客
        if (m_cmdList.find(index) == m_cmdList.end())
        {
            std::list<AbstractCommand*> mylist{ cmd };
            m_cmdList.insert(std::make_pair(index, mylist));
        }
        else
        {
            m_cmdList[index].push_back(cmd);
        }
    }
    // 取消订单
    void cancelOrder(int index, AbstractCommand* cmd)
    {
        if (m_cmdList.find(index) != m_cmdList.end())
        {
            m_cmdList[index].remove(cmd);
            std::cout << index << "号桌, 撤销了" << cmd->name() << std::endl;
        }
    }
    // 结账
    void checkOut(int index)
    {
        std::cout << "第[" << index << "]号桌的顾客点的菜是: 【";
        for (const auto& item : m_cmdList[index])
        {
            std::cout << item->name();
            if (item != m_cmdList[index].back())
            {
                std::cout << ", ";
            }
        }
        std::cout << "】" << std::endl;
    }
    void notify(int index)
    {
        for (const auto& item : m_cmdList[index])
        {
            item->excute();
            std::cout << index << "号桌" << std::endl;
        }
    }
private:
    // 存储顾客的下单信息
    std::map<int, std::list<AbstractCommand*>> m_cmdList;
};
