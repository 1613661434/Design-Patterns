#pragma once

#include <string>

// ============================================================================
// 单例模式 - 懒汉模式 (Lazy Initialization / Meyers' Singleton)
// S 类: 首次调用 getInstance() 时才创建唯一实例
// 利用 C++11 静态局部变量初始化是线程安全的特性
// 这是更好的单例实现方式，被注释为 "下面这种更好" 的版本
// ============================================================================
class S
{
public:
    std::string s;

    // 全局访问点，返回唯一实例的引用
    static S& getInstance()
    {
        static S instance;  // 静态局部变量，第一次调用时初始化，保证唯一性
        return instance;
    }

    // 禁止复制和赋值
    S(const S&) = delete;
    S& operator=(const S&) = delete;

private:
    // 私有构造函数，禁止外部创建实例
    S() = default;
};
