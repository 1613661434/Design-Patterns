# 组合模式 - 速查表

## 一句话总结
**将对象组织成树形结构，统一处理单个对象和组合对象。**

## ASCII 结构图

```
        AbstractTeam (Component)
        ├── fight() = 0
        ├── display() = 0
        ├── add(node)
        └── remove(node)
               │
     ┌─────────┴─────────┐
     │                   │
 LeafTeam           ManagerTeam (Composite)
 (Leaf)             ├── m_children: list<AbstractTeam*>
 无子节点            ├── add()    -- 添加子节点
 执行具体战斗         ├── remove() -- 移除子节点
                    └── fight()  -- 自己+子节点战斗

Client ---> AbstractTeam  (不区分叶子和组合)
```

## 核心角色

| 角色 | 职责 | 本例类名 |
|------|------|----------|
| Component | 定义叶子和组合的公共接口 | `AbstractTeam` |
| Leaf | 叶子节点，无子节点 | `LeafTeam` |
| Composite | 组合节点，管理子节点 | `ManagerTeam` |

## 何时使用

- 需要表示"部分-整体"的层次结构
- 希望对单个对象和组合对象使用统一的操作
- 树形结构: 文件系统、组织架构、UI组件树、游戏编队

## 透明组合 vs 安全组合

| 方式 | add/remove定义位置 | 优点 | 缺点 |
|------|--------------------|------|------|
| 透明组合 | Component中 (默认实现为空) | 客户端无需区分节点 | Leaf有无效方法 |
| 安全组合 | 仅在Composite中 | 类型安全 | 客户端需区分节点 |

**本例使用透明组合。**

## 关键代码

```cpp
// 客户端不区分叶子和组合, 统一调用
void gameover(AbstractTeam* root) {
    if (root->hasChild()) {
        // 组合节点: 先递归处理子节点
        for (auto child : dynamic_cast<ManagerTeam*>(root)->getChildren())
            gameover(child);
    }
    delete root;  // 统一释放
}
```

## 相关模式对比

| 模式 | 结构 | 意图 |
|------|------|------|
| 组合模式 | 树形 | 统一处理部分-整体 |
| 装饰模式 | 链式 | 动态添加功能 |
| 责任链模式 | 链式 | 依次传递请求 |
