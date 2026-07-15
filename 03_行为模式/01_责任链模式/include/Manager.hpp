#pragma once

#include <iostream>

enum class RequestType : char { QingJia, ZhangXin, CiZhi };

// 抽象的任务节点类
class AbstractManager
{
public:
    void setNext(AbstractManager* manager)
    {
        m_next = manager;
    }
    virtual void handleRequest(RequestType type) = 0;
    virtual ~AbstractManager() {}
protected:
    AbstractManager* m_next = nullptr;
};

// 初级管理者
class Manager : public AbstractManager
{
public:
    void handleRequest(RequestType type) override;
};

// CEO
class CEO : public AbstractManager
{
public:
    void handleRequest(RequestType type) override;
};

// 老板
class Boss : public AbstractManager
{
public:
    void handleRequest(RequestType type) override;
};

// 卑微的大聪明
class DaCongMing
{
public:
    void request(RequestType type, AbstractManager* manager)
    {
        manager->handleRequest(type);
    }
};
