# 适配器模式 - 速查表

## 一句话总结
**将不兼容的接口转换为客户端期望的接口，使原本无法合作的类可以一起工作。**

## ASCII 结构图

```
Client ---> Target (Panda) <--- Adapter (AbstractChopper) ---> Adaptee (Foreigner)
               |                      |                              |
               |             EnglishChopper (en)            American
               |             FrenchChopper (fr)             French
```

## 核心角色

| 角色 | 职责 | 本例类名 |
|------|------|----------|
| Target | 定义客户端使用的接口 | `Panda` |
| Adaptee | 需要被适配的现有接口 | `Foreigner`, `American`, `French` |
| Adapter | 适配器基类，持有Adaptee引用 | `AbstractChopper` |
| ConcreteAdapter | 具体适配器，完成接口转换 | `EnglishChopper`, `FrenchChopper` |

## 何时使用

- 想使用现有类，但其接口与需求不兼容
- 需要复用多个不兼容的类
- 需要对多个现有类进行统一的接口包装

## 类 vs 对象适配器

- **对象适配器** (本例): 适配器持有适配者实例（组合），更灵活
- **类适配器**: 适配器继承适配者（多重继承），C++中不常用

## 关键代码片段

```cpp
// 适配器持有目标对象和适配者引用
class AbstractChopper {
protected:
    Panda m_panda;                // Target
    Foreigner* m_foreigner;       // Adaptee
};

// 具体适配器完成翻译(接口转换)
void EnglishChopper::translateToPanda() {
    string msg = m_foreigner->confession();   // 获取Adaptee数据
    m_panda.recvMessage("美国人说: " + msg);    // 转换为Target格式
}
```

## 相关模式对比

| 模式 | 作用 |
|------|------|
| 桥接模式 | 分离抽象与实现，两者可独立变化 |
| 装饰模式 | 动态添加功能，不改变接口 |
| 代理模式 | 控制访问，接口不变 |
