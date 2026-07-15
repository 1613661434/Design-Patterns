#pragma once

#include <queue>
#include <mutex>
#include <string>

// ============================================================================
// 单例模式 - 饿汉模式 (Eager Initialization)
// TaskQueue 类: 线程安全的全局任务队列
// 类加载时立即创建实例，无需考虑线程同步问题
// ============================================================================
class TaskQueue
{
public:
    // 禁止复制和赋值
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator=(const TaskQueue& obj) = delete;

    // 全局访问点，返回唯一实例的指针
    static TaskQueue* getInstance()
    {
        return &m_obj;
    }

    // 任务队列是否为空
    bool isEmpty()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_taskQ.empty();
    }

    // 添加任务
    void addTask(int data)
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        m_taskQ.push(data);
    }

    // 取出一个任务 (不移除)
    int takeTask()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        if (!m_taskQ.empty())
        {
            return m_taskQ.front();
        }
        return -1;
    }

    // 删除一个任务
    bool popTask()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        if (!m_taskQ.empty())
        {
            m_taskQ.pop();
            return true;
        }
        return false;
    }

private:
    TaskQueue() = default;
    static TaskQueue m_obj;
    std::queue<int> m_taskQ;
    std::mutex m_mutex;
};
