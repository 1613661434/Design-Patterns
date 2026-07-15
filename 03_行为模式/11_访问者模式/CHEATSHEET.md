# 访问者模式 - 快速参考

## ASCII 结构图

```
┌──────────────────────────────────────────────────────┐
│        AbstractAction (抽象访问者)                     │
│  + maleDoing(MaleMember*) = 0                        │
│  + femalDoing(FemaleMember*) = 0                     │
└────────────────────┬─────────────────────────────────┘
                     △
        ┌────────────┴─────────────┐
        ▼                          ▼
┌───────────────┐          ┌──────────────┐
│    Anger      │          │    Horror    │
│  (愤怒访问者)  │          │  (恐惧访问者)  │
│ male: fight() │          │ male: think()│
│ female:warn() │          │ female:help()│
└───────┬───────┘          └──────┬───────┘
        │ 访问                    │ 访问
        ▼                         ▼
┌──────────────────────────────────────────────────────┐
│         AbstractMember (抽象元素)                      │
│  + accept(action) = 0       [双分派入口]               │
│  + getName()                                         │
│  # m_name                                            │
└────────────────────┬─────────────────────────────────┘
                     △
        ┌────────────┴─────────────┐
        ▼                          ▼
┌───────────────┐          ┌──────────────┐
│  MaleMember   │          │ FemaleMember │
│  (男性成员)    │          │  (女性成员)    │
│               │          │               │
│ accept(action)│          │ accept(action)│
│ ->action->    │          │ ->action->    │
│   maleDoing() │          │   femalDoing()│
└───────────────┘          └──────────────┘
        △                          △
        │ 包含                      │ 包含
┌──────────────────────────────────────────────────────┐
│           CaoMaoTeam (对象结构)                       │
│  + add(member) / remove(member)                      │
│  + display()  -> 随机分配 action 并调用 accept()       │
│  - m_members: list<AbstractMember*>                  │
│  - m_actions: vector<AbstractAction*>                │
└──────────────────────────────────────────────────────┘
```

## 双分派机制

```
第一次分派:  client 调用 member->accept(action)
               根据 member 类型分发 (MaleMember / FemaleMember)

第二次分派:  accept() 内部调用 action->maleDoing(this) 或 action->femalDoing(this)
               根据 action 类型分发 (Anger / Horror)

结果: 行为由 member类型 + action类型 两个维度共同决定
```

## 关键参与者

| 类 | 角色 | 方法 |
|----|------|------|
| `AbstractAction` | Visitor (访问者) | `maleDoing()`, `femalDoing()` |
| `Anger` | 愤怒访问者 | 男性战斗/女性警告 |
| `Horror` | 恐惧访问者 | 男性思考/女性呼救 |
| `AbstractMember` | Element (元素) | `accept(action)` |
| `MaleMember` | 男性元素 | `accept` -> `maleDoing` |
| `FemaleMember` | 女性元素 | `accept` -> `femalDoing` |
| `CaoMaoTeam` | 对象结构 | 管理成员和状态集合 |

## 何时使用

- 元素类稳定，但需要经常定义新操作
- 跨异构类执行操作（不同元素类型不同处理）
- 避免用类型判断（if-else / dynamic_cast）
- 编译器 AST 遍历、报表系统、统计分析

## 编译与运行

```bash
make
./main
```
