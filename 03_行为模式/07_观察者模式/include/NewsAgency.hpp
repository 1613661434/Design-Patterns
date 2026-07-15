#pragma once

#include <iostream>
#include <string>
#include <list>

class Observer;

// 新闻社 - 抽象主题
class NewsAgency
{
public:
    void attach(Observer* ob);
    void deatch(Observer* ob);
    virtual void notify(std::string msg) = 0;
    virtual ~NewsAgency() {};
protected:
    // 订阅者列表
    std::list<Observer*> m_list;
};
