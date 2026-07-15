#pragma once

#include <iostream>
#include <string>

// 历史备忘录类
class History
{
public:
    History(std::string msg) : m_msg(msg) {}
    std::string getHistory()
    {
        return m_msg;
    }
private:
    std::string m_msg;
};

// 脚盆鸡 - 原发器
class JiaoPenJi
{
public:
    void setState(std::string msg)
    {
        m_msg = msg;
    }

    std::string getState()
    {
        return m_msg;
    }

    void beiDaddyDa()
    {
        std::cout << "脚盆鸡被兔子狠狠地揍了又揍, 终于承认了它们之前不承认的这些罪行: " << std::endl;
    }

    History* saveHistory()
    {
        return new History(m_msg);
    }
    void getStateFromHistory(History* history)
    {
        m_msg = history->getHistory();
    }
private:
    std::string m_msg;
};
