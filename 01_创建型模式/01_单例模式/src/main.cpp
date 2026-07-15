#include "../include/TaskQueue.hpp"
#include "../include/LazySingleton.hpp"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// 静态成员初始化
TaskQueue TaskQueue::m_obj;

// ============================================================================
// 演示饿汉模式 (TaskQueue)
// 两个线程并发操作同一个任务队列
// ============================================================================
void demoEagerSingleton()
{
    cout << "========== 饿汉模式 (TaskQueue) ==========" << endl;

    thread t1([]() {
        TaskQueue* taskQ = TaskQueue::getInstance();
        for (int i = 0; i < 100; ++i)
        {
            taskQ->addTask(i + 100);
            cout << "+++push task: " << i + 100 << ", threadID: "
                 << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    });

    thread t2([]() {
        TaskQueue* taskQ = TaskQueue::getInstance();
        this_thread::sleep_for(chrono::milliseconds(100));
        while (!taskQ->isEmpty())
        {
            int data = taskQ->takeTask();
            cout << "---take task: " << data << ", threadID: "
                 << this_thread::get_id() << endl;
            taskQ->popTask();
            this_thread::sleep_for(chrono::seconds(1));
        }
    });

    t1.join();
    t2.join();
}

// ============================================================================
// 演示懒汉模式 (S - Meyers' Singleton)
// 验证多次调用 getInstance() 返回同一个对象
// ============================================================================
void demoLazySingleton()
{
    cout << "\n========== 懒汉模式 (S - Meyers' Singleton) ==========" << endl;

    S& instance1 = S::getInstance();
    instance1.s = "Hello, Singleton!";

    S& instance2 = S::getInstance();
    cout << "instance1.s = " << instance1.s << endl;
    cout << "instance2.s = " << instance2.s << endl;
    cout << "&instance1 == &instance2 ? "
         << (&instance1 == &instance2 ? "true (same object)" : "false") << endl;
}

int main()
{
    // 运行饿汉模式演示 (注意: 耗时较长因为有 sleep)
    // demoEagerSingleton();

    // 运行懒汉模式演示
    demoLazySingleton();

    return 0;
}
