#pragma once

#include <string>
#include "Visitor.hpp"

// 抽象的成员类 - 元素
class AbstractMember
{
public:
    AbstractMember(std::string name) : m_name(name) {}
    std::string getName()
    {
        return m_name;
    }
    // 接受状态对象的访问
    virtual void accept(AbstractAction* action) = 0;
    virtual ~AbstractMember() {}
protected:
    std::string m_name;
};

// 男性成员
class MaleMember : public AbstractMember
{
public:
    using AbstractMember::AbstractMember;
    void accept(AbstractAction* action) override
    {
        action->maleDoing(this);
    }
};

// 女性成员
class FemaleMember : public AbstractMember
{
public:
    using AbstractMember::AbstractMember;
    void accept(AbstractAction* action) override
    {
        action->femalDoing(this);
    }
};
