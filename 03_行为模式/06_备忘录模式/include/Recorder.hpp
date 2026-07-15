#pragma once

#include "Memento.hpp"
#include <map>

// 记录者 - 管理者
class Recorder
{
public:
    void addHistory(int index, History* history)
    {
        m_history.insert(std::make_pair(index, history));
    }
    History* getHistory(int index)
    {
        if (m_history.find(index) != m_history.end())
        {
            return m_history[index];
        }
        return nullptr;
    }
private:
    std::map<int, History*> m_history;
};
