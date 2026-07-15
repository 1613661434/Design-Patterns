# 备忘录模式 - 快速参考

## ASCII 结构图

```
┌────────────────────────────────────────────────────┐
│              Originator (JiaoPenJi)                │
│              "脚盆鸡" - 原发器                       │
│  + setState(msg)                                   │
│  + getState() -> string                            │
│  + saveHistory() -> History*    (创建备忘录)        │
│  + getStateFromHistory(h)      (恢复状态)           │
│  - m_msg: string                                   │
└────────┬──────────────────────────┬────────────────┘
         │ 创建/使用                  │ 依赖
         ▼                           ▼
┌──────────────────┐    ┌──────────────────────────┐
│  History (备忘录) │    │   Recorder (Caretaker)   │
│  - m_msg: string │    │   管理者/记录者            │
│  + getHistory()  │    │  + addHistory(idx, hist)  │
│       -> string  │    │  + getHistory(idx)->Hist* │
└──────────────────┘    │  - m_history: map<int,..> │
                        └──────────────────────────┘

                Client (main)
                 1. setState -> saveHistory -> Recorder.addHistory()
                 2. beiDaddyDa() (触发恢复)
                 3. for each: Recorder.getHistory() -> getStateFromHistory()
```

## 关键参与者

| 类 | 角色 | 职责 |
|----|------|------|
| `JiaoPenJi` | Originator (原发器) | 创建和恢复备忘录 |
| `History` | Memento (备忘录) | 不可变状态快照 |
| `Recorder` | Caretaker (管理者) | 存储/检索备忘录 |

## 调用流程

```
1. 保存: jiaopen->setState(msg) -> jiaopen->saveHistory() -> recorder->addHistory(idx, hist)
2. 触发: jiaopen->beiDaddyDa() 
3. 恢复: recorder->getHistory(i) -> jiaopen->getStateFromHistory(hist) -> jiaopen->getState()
```

## 何时使用

- 需要撤销/恢复功能（Undo/Redo）
- 需要保存对象快照以便将来恢复
- 不希望暴露对象内部状态给外部访问
- 游戏存档、文档版本管理、数据库事务

## 编译与运行

```bash
make
./main
```
