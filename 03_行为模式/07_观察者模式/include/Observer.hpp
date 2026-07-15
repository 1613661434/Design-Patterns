#pragma once

#include <string>
#include "NewsAgency.hpp"

// 抽象的订阅者类
class Observer
{
public:
    Observer(std::string name, NewsAgency* news) : m_name(name), m_news(news)
    {
        m_news->attach(this);
    }
    void unsubscribe()
    {
        m_news->deatch(this);
    }
    virtual void update(std::string msg) = 0;
    virtual ~Observer() {}
protected:
    std::string m_name;
    NewsAgency* m_news;
};
