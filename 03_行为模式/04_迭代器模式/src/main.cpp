#include "Iterator.hpp"
#include <iostream>
#include <vector>

// ============ MyList 成员函数实现 ============

Node* MyList::insert(Node* item, std::string data)
{
    Node* node = nullptr;
    if (item == m_head)
    {
        node = pushFront(data);
    }
    else
    {
        node = new Node(data);
        node->next = item;
        node->prev = item->prev;
        // 重新连接
        item->prev->next = node;
        item->prev = node;
        m_count++;
    }
    return node;
}

Node* MyList::pushFront(std::string data)
{
    Node* node = new Node(data);
    // 空链表
    if (m_head == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }
    m_count++;
    return node;
}

Node* MyList::pushBack(std::string data)
{
    Node* node = new Node(data);
    // 空链表
    if (m_tail == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        m_tail->next = node;
        node->prev = m_tail;
        m_tail = node;
    }
    m_count++;
    return node;
}

Iterator* MyList::getIterator(bool isReverse)
{
    Iterator* iterator = nullptr;
    if (isReverse)
    {
        iterator = new ReverseIterator(this);
    }
    else
    {
        iterator = new ForwardIterator(this);
    }
    return iterator;
}

// ============ 迭代器成员函数实现 ============

Node* ForwardIterator::first()
{
    m_current = m_list->head();
    return m_current;
}

Node* ForwardIterator::next()
{
    m_current = m_current->next;
    return m_current;
}

bool ForwardIterator::isDone()
{
    return m_current == m_list->tail()->next;
}

Node* ReverseIterator::first()
{
    m_current = m_list->tail();
    return m_current;
}

Node* ReverseIterator::next()
{
    m_current = m_current->prev;
    return m_current;
}

bool ReverseIterator::isDone()
{
    return m_current == m_list->head()->prev;
}

// ============ main ============

int main()
{
    std::vector<std::string> nameList{
        "烬", "奎因", "杰克", "福兹·弗", "X·德雷克",
        "黑色玛利亚", "笹木", "润媞", "佩吉万",
        "一美", "二牙", "三鬼", "四鬼", "五鬼",
        "六鬼", "七鬼", "八茶", "九忍","十鬼"
    };
    MyList mylist;
    for (std::size_t i = 0; i < nameList.size(); ++i)
    {
        mylist.pushBack(nameList.at(i));
    }
    // 遍历
    Iterator* it = mylist.getIterator(true);
    std::cout << "检阅开始, 凯多: 同志们辛苦啦~~~~~" << std::endl;
    for (it->first(); !it->isDone(); it->next())
    {
        std::cout << "   " << it->current()->name << "say: 为老大服务!!! " << std::endl;
    }
    std::cout << std::endl;
    delete it;
    return 0;
}
