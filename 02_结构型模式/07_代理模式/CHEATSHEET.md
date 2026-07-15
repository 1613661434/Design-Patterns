# 代理模式 - 速查表

## 一句话总结
**通过代理对象控制对原始对象的访问，接口不变，功能增强。**

## ASCII 结构图

```
Client ──> Communication (Subject)
              │
     ┌────────┴────────┐
     │                 │
  Speaker         DenDenMushi (Proxy)
  (RealSubject)   ├── m_speaker: Speaker*
  实际上说话       ├── m_isStart: bool
  +communicate()  └── communicate()
                        │
                        ① 检查状态 (isStart)
                        ② 附加逻辑 (模仿表情)
                        ③ 委托给 Speaker::communicate()
```

## 核心角色

| 角色 | 职责 | 本例类名 |
|------|------|----------|
| Subject | 定义代理和真实对象的公共接口 | `Communication` |
| RealSubject | 实现实际业务逻辑 | `Speaker` |
| Proxy | 持有RealSubject引用,控制访问 | `DenDenMushi` |

## 何时使用

- 需要控制对对象的访问权限
- 需要延迟加载重量级对象 (虚拟代理)
- 需要为远程对象提供本地代表 (远程代理)
- 需要在访问对象时添加日志/缓存/计数

## 代理 vs 装饰

| 特性 | 代理 | 装饰 |
|------|------|------|
| 目的 | 控制访问 | 增强功能 |
| 谁创建被包裹对象 | 代理自身 | 外部传入 |
| 关系 | 代表关系 | 包装关系 |
| 例子 | 电话虫(DenDenMushi) | 恶魔果实(DarkFruit) |

```cpp
// 代理: 自己创建真实对象
class DenDenMushi : public Communication {
    DenDenMushi() { m_speaker = new Speaker; }  // 内部创建
};

// 装饰: 从外部接收对象
class DevilFruitDecorator : public Soldier {
    DevilFruitDecorator(unique_ptr<Soldier> s) : soldier(move(s)) {} // 外部传入
};
```

## 关键代码

```cpp
// 代理在调用真实对象前/后添加控制逻辑
void DenDenMushi::communicate() override {
    if (isStart()) {                                // ① 访问控制
        cout << "电话虫开始实时模仿..." << endl;      // ② 附加行为(前)
        m_speaker->communicate();                   // ③ 委托真实对象
        // 也可在之后添加行为 (后)
    }
}
```

## 代理模式变体

| 变体 | 用途 |
|------|------|
| 远程代理 | 隐藏远程对象的位置 |
| 虚拟代理 | 延迟创建开销大的对象 |
| 保护代理 | 访问权限控制 |
| 智能引用 | 引用计数、锁等附加操作 |

## 相关模式对比

| 模式 | 接口 | 意图 |
|------|------|------|
| 代理 | 相同 | 控制访问 |
| 装饰 | 相同 | 增强功能 |
| 适配器 | 不同 | 接口转换 |
| 外观 | 简化 | 封装复杂性 |
