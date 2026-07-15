# 迭代器模式 - 快速参考

## ASCII 结构图

```
┌──────────────────────────────────────────────┐
│                   MyList (具体集合)            │
│  + head() -> Node*                           │
│  + tail() -> Node*                           │
│  + pushFront/Back/Insert(data)               │
│  + getIterator(isReverse) -> Iterator*       │
│                                               │
│  双向链表: head ⟷ ... ⟷ tail                 │
└───────────────────┬──────────────────────────┘
                    │ 创建
                    ▼
┌──────────────────────────────────────────────┐
│              Iterator (抽象迭代器)             │
│  + first() -> Node*    (纯虚)                 │
│  + next()  -> Node*    (纯虚)                 │
│  + isDone() -> bool    (纯虚)                 │
│  + current() -> Node*                        │
│  # m_list, m_current                         │
└───────────────────┬──────────────────────────┘
                    △
        ┌───────────┴───────────┐
        ▼                       ▼
┌───────────────┐       ┌───────────────┐
│ForwardIterator│       │ReverseIterator│
│ first()=head  │       │ first()=tail  │
│ next()=next   │       │ next()=prev   │
│ isDone()=tail │       │ isDone()=head │
│   ->next      │       │   ->prev      │
└───────────────┘       └───────────────┘
```

## 关键参与者

| 类 | 职责 | 遍历方向 |
|----|------|----------|
| `Node` | 链表节点，含 name、next、prev | -- |
| `MyList` | 双向链表，提供增删和获取迭代器 | -- |
| `Iterator` | 抽象迭代器基类 | -- |
| `ForwardIterator` | 正向：head -> tail | head 开始，next 前进 |
| `ReverseIterator` | 逆向：tail -> head | tail 开始，prev 前进 |

## 调用流程

```cpp
MyList list;
list.pushBack("烬"); // 建表
Iterator* it = list.getIterator(true); // 获取逆向迭代器
for (auto begin = it->first(); !it->isDone(); it->next()) {
    cout << it->current()->name;
}
delete it;
```

## 何时使用

- 需要不暴露内部结构地遍历集合
- 需要多种遍历方式（正向、逆向、按条件等）
- 需要为不同集合提供统一遍历接口
- 自定义数据结构的遍历

## 编译与运行

```bash
make
./main
```
