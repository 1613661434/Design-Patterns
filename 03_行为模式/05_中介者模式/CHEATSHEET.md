# 中介者模式 - 快速参考

## ASCII 结构图

```
                    ┌──────────────────────┐
                    │    MediatorOrg       │
                    │   (抽象中介机构)       │
                    │ + addMember()        │
                    │ + declare() = 0      │
                    │ # m_countryMap       │
                    └──────┬───────────────┘
                           △
              ┌────────────┴────────────┐
              ▼                         ▼
   ┌──────────────────┐      ┌──────────────────┐
   │   WorldGovt      │      │   GeMingArmy     │
   │   (世界政府)      │      │   (革命军)        │
   │ 点对点发送        │      │ 广播发送(排除自己) │
   └────┬─────────────┘      └────┬─────────────┘
        │ m_countryMap            │ m_countryMap
        │                         │
   ┌────┴─────────────────────────┴────┐
   │         Country (抽象国家)         │
   │  + declare(msg, country) = 0      │
   │  + setMessage(msg) = 0            │
   │  + getName() = 0                  │
   │  # m_mediator                     │
   └────────────────┬──────────────────┘
                    △
   ┌───────┬────────┼────────┬──────────┐
   ▼       ▼        ▼       ▼          ▼
Alabasta Dressrosa Lulusia Kamabaka  (更多...)
```

## 关键参与者

| 类 | 职责 | 发送策略 |
|----|------|----------|
| `MediatorOrg` | 抽象中介，定义 `addMember()` 和 `declare()` | -- |
| `WorldGovt` | 世界政府，点对点通信 | 仅发给指定国家 |
| `GeMingArmy` | 革命军，广播通信 | 发给所有其他成员 |
| `Country` | 抽象国家，持有中介者引用 | -- |
| `Alabasta` 等 | 具体国家 | 通过中介者发送消息 |

## 调用流程

```
Country -> MediatorOrg.declare(msg, this, target)
  -> WorldGovt: 在 map 中查找 target，调用 target->setMessage()
  -> GeMingArmy: 遍历所有国家，排除发送者，广播 setMessage()
```

## 何时使用

- 多个对象有复杂的交互关系，形成网状结构
- 需要集中管理对象间的通信逻辑
- 需要复用对象但交互逻辑差异大
- GUI 组件、聊天室、交通调度、微服务编排

## 编译与运行

```bash
make
./main
```
