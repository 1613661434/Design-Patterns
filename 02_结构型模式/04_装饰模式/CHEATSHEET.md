# 装饰模式 - 速查表

## 一句话总结
**不修改原对象，动态地为其添加新功能（像穿衣服一样层层包裹）。**

## ASCII 结构图

```
   Client ──> Soldier (Component)
                 │
        ┌────────┴────────┐
        │                 │
      Teach        DevilFruitDecorator (Decorator)
   (Concrete)       ├── soldier: unique_ptr<Soldier>
   原始体术          └── fight() 委托给 soldier + 新能力
                         │
              ┌──────────┼──────────┐
              │          │          │
          DarkFruit  QuakeFruit  PieFruit
          (暗暗)      (震震)      (大饼)
```

## 包装过程 (层层包裹)

```
Teach
  └── DarkFruit    (Teach被DarkFruit包裹)
        └── QuakeFruit   (DarkFruit被QuakeFruit包裹)
              └── PieFruit    (QuakeFruit被PieFruit包裹)

// fight()调用链:
PieFruit::fight()
  -> QuakeFruit::fight()
    -> DarkFruit::fight()
      -> Teach::fight()      // 黑胡子体术
      + 暗暗果实能力
    + 震震果实能力
  + 大饼果实能力
```

## 核心角色

| 角色 | 职责 | 本例类名 |
|------|------|----------|
| Component | 定义对象接口 | `Soldier` |
| ConcreteComponent | 被装饰的原始对象 | `Teach` |
| Decorator | 持有Component引用，接口一致 | `DevilFruitDecorator` |
| ConcreteDecorator | 添加具体新功能 | `DarkFruit`, `QuakeFruit`, `PieFruit` |

## 何时使用

- 需要动态为对象添加功能，随时可撤销
- 无法用继承扩展（类为final，或组合爆炸）
- 需要运行时组合多个可选功能
- 功能扩展不影响其他对象

## 装饰 vs 继承

| 特性 | 装饰模式 | 继承 |
|------|----------|------|
| 扩展方式 | 组合+委托 | 子类化 |
| 添加时机 | 运行时 | 编译时 |
| 组合性 | 可任意组合 | 组合导致类爆炸 |
| 撤销 | 容易 | 无法撤销 |

## 关键代码

```cpp
// 层层包装 (所有权转移)
unique_ptr<Soldier> s = make_unique<Teach>("黑胡子");
s = make_unique<DarkFruit>(move(s));   // s现在指向DarkFruit

// 透明调用: 客户端不感知装饰器存在
s->fight();  // 自动触发整条链
```

## 相关模式对比

| 模式 | 目标 |
|------|------|
| 装饰模式 | 动态添加功能，增强对象 |
| 代理模式 | 控制访问，接口不变 |
| 适配器模式 | 转换接口，使不兼容的类协作 |
| 组合模式 | 树形结构，统一处理部分-整体 |
