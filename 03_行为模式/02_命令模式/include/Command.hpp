#pragma once

#include <iostream>
#include <string>

// 厨师哲普 - 接收者
class CookerZeff
{
public:
    void makeDSX()
    {
        std::cout << "开始烹饪地三鲜...";
    }
    void makeGBJD()
    {
        std::cout << "开始烹饪宫保鸡丁...";
    }
    void makeYXRS()
    {
        std::cout << "开始烹饪鱼香肉丝...";
    }
    void makeHSPG()
    {
        std::cout << "开始烹饪红烧排骨...";
    }
};

// 点餐的命令 - 抽象类
class AbstractCommand
{
public:
    AbstractCommand(CookerZeff* receiver) : m_cooker(receiver) {}
    virtual void excute() = 0;
    virtual std::string name() = 0;
    virtual ~AbstractCommand() {}
protected:
    CookerZeff* m_cooker = nullptr;
};

// 地三鲜的命令
class DSXCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeDSX();
    }
    std::string name() override
    {
        return "地三鲜";
    }
};

// 宫保鸡丁的命令
class GBJDCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeGBJD();
    }
    std::string name() override
    {
        return "宫保鸡丁";
    }
};

// 鱼香肉丝的命令
class YXRSCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeYXRS();
    }
    std::string name() override
    {
        return "鱼香肉丝";
    }
};

// 红烧排骨的命令
class HSPGCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeHSPG();
    }
    std::string name() override
    {
        return "红烧排骨";
    }
};
