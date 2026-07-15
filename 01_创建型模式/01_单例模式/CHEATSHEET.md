# 单例模式 速查表

## 一句话总结
确保一个类只有一个实例，并提供全局访问点。

## 两种实现对比

| 特性 | 饿汉模式 (Eager) | 懒汉模式 (Lazy/Meyers) |
|------|-----------------|----------------------|
| 创建时机 | 类加载时 | 首次调用时 |
| 线程安全 | 是 (main前初始化) | 是 (C++11 静态局部变量) |
| 资源占用 | 可能浪费 | 按需创建 |
| 推荐程度 | 一般 | **推荐** |

## ASCII 结构图

```
        getInstance() 调用
              │
              ▼
    ┌─────────────────────┐
    │  static instance?   │
    │  存在 / 不存在       │
    └──────┬───┬──────────┘
           │   │
    存在   │   │  不存在 (懒汉首次)
           │   ▼
           │  new Singleton()
           │   │
           ▼   ▼
    ┌─────────────────────┐
    │  return unique ptr  │
    └─────────────────────┘
```

## 关键代码骨架

```cpp
// 推荐写法: Meyers' Singleton
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;  // C++11 线程安全
        return instance;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
private:
    Singleton() = default;
};
```

## 关键规则
1. 构造函数 **private**
2. 拷贝构造和赋值运算符 **= delete**
3. 静态成员函数 **getInstance()** 返回引用或指针
4. (懒汉) 静态局部变量在 C++11 起线程安全

## 适用/不适用

**适用**:
- 全局配置管理、日志记录器
- 数据库连接池、线程池
- 设备驱动对象

**不适用**:
- 需要多个不同配置的对象
- 需要 mock 进行单元测试的场景
- 状态变化频繁且需要隔离的对象
