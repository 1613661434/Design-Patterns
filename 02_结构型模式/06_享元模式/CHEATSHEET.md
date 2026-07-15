# 享元模式 - 速查表

## 一句话总结
**共享相同数据，节省内存 -- 内部状态共享，外部状态独立。**

## ASCII 结构图

```
BombBodyFactory (享元工厂)
  │
  │ getSharedData("撒旦-1") ──> 若存在则复用, 否则创建
  │
  └──> map<name, SharedBombBody*>  (共享对象池)
              │
              │  ┌── "撒旦-1" → obj1  (被 LaunchBomb_A 和 LaunchBomb_B 共享)
              │  ├── "撒旦-2" → obj2  (被 LaunchBomb_C/D/E 共享)
              │  └── "撒旦-3" → obj3
              │
              v
  FlyweightBody (抽象享元)
  ├── m_sprite  (内部状态 - 共享)
  └── m_color   (内部状态 - 共享)
        │
  ┌─────┴──────────┬──────────────┐
  │                │              │
SharedBombBody  UniqueBomb    (也可用Unique)
  (可共享)        (唯一,不共享)

LaunchBomb (客户端)
  ├── m_bomb*   (引用共享享元)
  ├── m_x       (外部状态 - 独立)
  ├── m_y       (外部状态 - 独立)
  └── m_speed   (外部状态 - 独立)
```

## 核心角色

| 角色 | 职责 | 本例类名 |
|------|------|----------|
| Flyweight | 定义享元接口 | `FlyweightBody` |
| ConcreteFlyweight | 可共享的享元 | `SharedBombBody` |
| UniqueFlyweight | 唯一(不共享)享元 | `UniqueBomb` |
| FlyweightFactory | 管理享元创建与共享 | `BombBodyFactory` |
| Client | 使用享元,维护外部状态 | `LaunchBomb` |

## 何时使用

- 大量相似对象导致内存不足
- 对象的大部分状态可外部化
- 去除外部状态后可用少量共享对象替换

## 内部状态 vs 外部状态

```
 内部状态 (存在享元中,共享)     外部状态 (存在客户端,独立)
┌─────────────────────┐    ┌─────────────────────┐
│ m_sprite (精灵图)    │    │ m_x, m_y (坐标)     │
│ m_color  (颜色)      │    │ m_speed (速度)      │
└─────────────────────┘    └─────────────────────┘
    一份即可复用              每个对象各不相同
```

## 关键代码

```cpp
// 工厂: 同名弹体只创建一次, 后续复用
SharedBombBody* BombBodyFactory::getSharedData(const string& name) {
    // 1. 查找缓存 map
    // 2. 找到 → 复用 ("正在复用...")
    // 3. 未找到 → 创建新对象 → 存入缓存 → 返回
}

// 客户端: 持有共享弹体 + 独立的外部状态
class LaunchBomb {
    FlyweightBody* m_bomb;   // 共享的内部状态引用
    int m_x, m_y, m_speed;   // 独立的外部状态
};
```

## 相关模式对比

| 模式 | 共享方式 |
|------|----------|
| 享元模式 | 共享不可变内部状态 |
| 单例模式 | 全局唯一实例 |
| 对象池模式 | 复用可变对象 |
| 原型模式 | 克隆对象 |
