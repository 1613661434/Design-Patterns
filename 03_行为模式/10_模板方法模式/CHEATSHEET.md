# 模板方法模式 - 快速参考

## ASCII 结构图

```
┌──────────────────────────────────────────────────────┐
│              AbstractRobot (抽象类)                    │
│  + getProperty()  [模板方法 - 算法骨架]                 │
│    {                                                 │
│      print getName();                                │
│      if (canFlying())  ...  // 钩子方法               │
│      if (isAuto())     ...  // 钩子方法               │
│      weapon();             // 抽象方法 (子类实现)       │
│      appearance();         // 抽象方法 (子类实现)       │
│      fightAbility();       // 抽象方法 (子类实现)       │
│      selfHealing();        // 钩子方法 (可选覆盖)       │
│    }                                                 │
│  + weapon() = 0          [纯虚 - 必须实现]              │
│  + appearance() = 0      [纯虚 - 必须实现]              │
│  + fightAbility() = 0    [纯虚 - 必须实现]              │
│  + getName() = 0         [纯虚 - 必须实现]              │
│  + canFlying() { false } [钩子 - 可选覆盖]              │
│  + isAuto() { true }     [钩子 - 可选覆盖]              │
│  + selfHealing() {}      [钩子 - 可选覆盖]              │
└────────────────────┬─────────────────────────────────┘
                     △
        ┌────────────┴─────────────┐
        ▼                          ▼
┌───────────────┐          ┌──────────────┐
│   Pacifist    │          │   Seraphim   │
│  (和平主义者)  │          │   (炽天使)    │
│                │          │               │
│ canFlying=F    │          │ canFlying=T   │
│ isAuto=T       │          │ isAuto=T      │
│ selfHealing=-  │          │ selfHealing=T │
└───────────────┘          └──────────────┘
```

## 关键参与者

| 类 | 角色 | 飞行 | 自愈 |
|----|------|------|------|
| `AbstractRobot` | 抽象模板 | 无 (默认) | 无 (默认) |
| `Pacifist` | 和平主义者 | 无 | 无 |
| `Seraphim` | 炽天使 | 有 (覆盖钩子) | 有 (覆盖钩子) |

## 调用流程

```
robot->getProperty() (模板方法)
  -> getName()
  -> canFlying() -> 输出飞行能力
  -> isAuto() -> 输出控制方式
  -> weapon() -> 输出武器信息
  -> appearance() -> 输出外观信息
  -> fightAbility() -> 输出战斗能力
  -> selfHealing() -> 输出自愈能力
```

## 何时使用

- 算法骨架固定，部分步骤可以不同实现
- 需要控制子类的扩展流程
- 多个子类的公共行为需要集中管理
- 框架设计、构建流程、数据导入/导出流程

## 编译与运行

```bash
make
./main
```
