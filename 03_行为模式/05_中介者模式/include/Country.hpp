#pragma once

#include <string>

class MediatorOrg;

// 抽象国家类
class Country
{
public:
    Country(MediatorOrg* mediator) : m_mediator(mediator) {}
    // 发表声明
    virtual void declare(std::string msg, std::string country) = 0;
    virtual void setMessage(std::string msg) = 0;
    virtual std::string getName() = 0;
    virtual ~Country() {}
protected:
    MediatorOrg* m_mediator = nullptr;
};
