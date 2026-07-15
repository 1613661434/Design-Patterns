#pragma once

#include "NodeList.hpp"

// 抽象的迭代器类
class Iterator
{
public:
    Iterator(MyList* mylist) : m_list(mylist) {}
    Node* current()
    {
        return m_current;
    }
    virtual Node* first() = 0;
    virtual Node* next() = 0;
    virtual bool isDone() = 0;
    virtual ~Iterator() {}
protected:
    MyList* m_list = nullptr;
    Node* m_current = nullptr;
};

// 正向迭代器
class ForwardIterator : public Iterator
{
public:
    using Iterator::Iterator;
    Node* first() override;
    Node* next() override;
    bool isDone() override;
};

// 逆向迭代器
class ReverseIterator : public Iterator
{
public:
    using Iterator::Iterator;
    Node* first() override;
    Node* next() override;
    bool isDone() override;
};
