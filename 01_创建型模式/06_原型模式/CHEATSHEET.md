# 原型模式 速查表

## 一句话总结
通过**克隆**现有对象来创建新对象，而非 new。

## ASCII 结构图

```
  原型对象 (prototype)
       │
       │  clone()
       ▼
  ┌──────────┐  拷贝构造    ┌──────────┐
  │ Soldier66 │ ──────────> │ Soldier66 │  (克隆体)
  │ (原始)    │  *this       │ (副本)    │
  └──────────┘              └──────────┘

  本质: new ConcretePrototype(*this)
```

## 关键代码骨架

```cpp
// 抽象原型
class GermaSoldier {
public:
    virtual GermaSoldier* clone() = 0;  // 克隆自身
    virtual ~GermaSoldier() = default;
};

// 具体原型
class Soldier66 : public GermaSoldier {
public:
    GermaSoldier* clone() override {
        return new Soldier66(*this);  // 使用拷贝构造
    }
};

// 使用
GermaSoldier* proto = new Soldier66;
GermaSoldier* copy = proto->clone();  // 克隆！
delete proto;
delete copy;
```

## 浅拷贝 vs 深拷贝

| 特性 | 浅拷贝 (Shallow) | 深拷贝 (Deep) |
|------|-----------------|--------------|
| 复制内容 | 对象本身 | 对象+所有引用的对象 |
| 指针处理 | 复制地址 | 复制指向的内容 |
| 内存独立性 | 共享 | 完全独立 |
| 实现难度 | 简单 (默认拷贝构造) | 需手动实现 |

## 适用/不适用

**适用**:
- 对象创建成本高（复杂初始化、网络/数据库读取）
- 需要大量相似对象（游戏中的敌人、粒子效果）
- 需要保存对象状态并克隆

**不适用**:
- 对象简单，创建开销小
- 对象包含循环引用
- 类的构造过程有副作用（如分配系统资源）

## 与其它创建型模式的对比

| 模式 | 创建机制 | 适用场景 |
|------|---------|---------|
| 单例 | 全局唯一 | 只需1个 |
| 简单工厂 | 参数→new | 简单选择 |
| 工厂方法 | 子类决定new | 1产品→1工厂 |
| 抽象工厂 | 创建产品族 | 系列相关产品 |
| 建造者 | 分步构建 | 复杂对象 |
| **原型** | **克隆** | **对象创建成本高** |
