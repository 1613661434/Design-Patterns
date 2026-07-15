# 策略模式 - 快速参考

## ASCII 结构图

```
┌──────────────────────────────────────────────────────┐
│            AbstractStrategy (抽象策略)                 │
│  + fight(isfar = false) = 0                          │
└────────────────────┬─────────────────────────────────┘
                     △
  ┌────────┬─────────┼─────────┬──────────┐
  ▼        ▼         ▼         ▼          ▼
┌──────┐┌──────┐┌──────┐┌──────┐┌──────────┐
│YiDang││ErDang││SanDng││SiDang││WuDang    │
│一档   ││二挡   ││三挡   ││四挡   ││五档       │
│Easy  ││Normal││Hard  ││Expert││Professnl │
└──────┘└──────┘└──────┘└──────┘└──────────┘
                     ▲
                     │ 持有并使用
┌──────────────────────────────────────────────────────┐
│                Luffy (Context / 上下文)                │
│  + fight(level, isfar)                               │
│     根据 Level 枚举创建对应 Strategy                     │
│  - m_strategy: AbstractStrategy*                     │
└──────────────────────────────────────────────────────┘

Level 枚举: Easy -> Normal -> Hard -> Experts -> Professional
              一档      二挡      三挡     四挡        五档
```

## 关键参与者

| 类 | 角色 | 档位/级别 |
|----|------|-----------|
| `AbstractStrategy` | 抽象策略 | -- |
| `YiDang` | 具体策略 | 一档 (Easy) |
| `ErDang` | 具体策略 | 二挡 (Normal) |
| `SanDang` | 具体策略 | 三挡 (Hard) |
| `SiDang` | 具体策略 | 四挡 (Experts) |
| `WuDang` | 具体策略 | 五档 (Professional) |
| `Luffy` | 上下文 | 持有当前策略 |

## 调用流程

```
Luffy::fight(Level::Hard, isFar=false)
  -> 删除旧策略
  -> switch(level) 创建 SanDang
  -> m_strategy->fight(false)
  -> SanDang::fight(false) 输出 "橡胶巨人战斧"
```

## 何时使用

- 需要动态切换算法（如不同难度/档位）
- 消除大量条件分支（if-else / switch）
- 算法/行为可独立变化，不需修改使用方
- 排序算法、支付方式、压缩算法、战斗系统

## 编译与运行

```bash
make
./main
```
