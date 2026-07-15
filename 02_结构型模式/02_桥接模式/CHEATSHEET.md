# 桥接模式 - 速查表

## 一句话总结
**将抽象与实现分离，使两者可以独立变化。（用组合代替继承）**

## ASCII 结构图

```
            Bridge (组合关系)
    ┌──────────┐          ┌──────────────┐
    │ AbstractShip │──────>│  AbstractTeam  │  <-- Implementor
    │ (Abstraction)│  m_team│  + executeTask()│
    └─────┬────────┘          └──────┬───────┘
          │                          │
  ┌───────┼────────┐        ┌───────┼────────┐
  │               │        │                │
Merry        HaiJunShip   CaoMaoTeam    SmokerTeam
(Refined     (Refined     (Concrete      (Concrete
Abstraction) Abstraction) Implementor)   Implementor)

Team <── Person (Data Class)
```

## 核心角色

| 角色 | 职责 | 本例类名 |
|------|------|----------|
| Abstraction | 定义抽象接口，持有Implementor引用 | `AbstractShip` |
| RefinedAbstraction | 扩展抽象接口 | `Merry`, `HaiJunShip` |
| Implementor | 定义实现接口 | `AbstractTeam` |
| ConcreteImplementor | 具体实现 | `CaoMaoTeam`, `SmokerTeam` |

## 何时使用

- 一个类存在多个独立变化的维度
- 需要避免永久性的静态绑定（继承）
- 需要在运行时动态切换实现
- 抽象和实现都需要独立扩展

## 桥接 vs 继承

```cpp
// 错误方式: 用继承会导致类爆炸
// MerryWithCaoMao, MerryWithSmoker, HaiJunWithCaoMao, HaiJunWithSmoker...

// 正确方式: 用桥接(组合)
AbstractShip* ship = new Merry(new CaoMaoTeam("草帽团"));
// 可任意组合, 无需为每种组合创建新类
```

## 关键代码

```cpp
// 抽象持有实现的引用 (组合)
class AbstractShip {
protected:
    AbstractTeam* m_team;  // 桥接到实现
};

// 运行时绑定: 船持有任意团队
Merry* sunny = new Merry(caomao);  // 梅利号 + 草帽团
```

## 相关模式对比

| 模式 | 关系 | 意图 |
|------|------|------|
| 桥接 | 组合 | 分离抽象与实现 |
| 适配器 | 组合 | 转换不兼容接口 |
| 策略 | 组合 | 封装可互换算法 |
