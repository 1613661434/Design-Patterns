#pragma once

#include <string>

// 定义一个链表节点
struct Node
{
    Node(std::string n) : name(n) {}
    std::string name = std::string();
    Node* next = nullptr;
    Node* prev = nullptr;
};

class Iterator;

// 双向链表
class MyList
{
public:
    inline int getCount()
    {
        return m_count;
    }

    inline Node* head()
    {
        return m_head;
    }

    inline Node* tail()
    {
        return m_tail;
    }

    Node* insert(Node* item, std::string data);
    Node* pushFront(std::string data);
    Node* pushBack(std::string data);
    Iterator* getIterator(bool isReverse = false);

private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_count = 0;
};
