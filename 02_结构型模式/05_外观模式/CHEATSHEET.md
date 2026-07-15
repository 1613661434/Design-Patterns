# 外观模式 - 速查表

## 一句话总结
**为复杂子系统提供一个简单的统一入口，隐藏内部复杂性。**

## ASCII 结构图

```
Client ──> LionCannon (Facade) ──┬── CokeSystem     (注入可乐)
                │                ├── EnergySystem   (能量转换)
           aimAndLock() ─────────┤── AimLockSystem  (目标锁定)
           fire()      ─────────┼── Cannon         (开炮)
                                 └── WindCannon     (风来炮稳定)

// 客户端无需了解5个子系统, 只需调用两个方法
```

## 核心角色

| 角色 | 职责 | 本例类名 |
|------|------|----------|
| Facade | 封装子系统,提供简单接口 | `LionCannon` |
| Subsystem | 实现具体功能 | `CokeSystem`, `EnergySystem`, `AimLockSystem`, `Cannon`, `WindCannon` |

## 何时使用

- 复杂系统需要简化入口
- 子系统之间的依赖关系复杂
- 需要将系统分层
- 希望降低客户端与子系统的耦合

## 发射流程 (狮吼炮)

```
aimAndLock():
  1. CokeSystem::immitCoke()       → 注入可乐
  2. EnergySystem::energyConvert() → 能量转换
  3. AimLockSystem::aimLock()      → 目标锁定

fire():
  4. Cannon::cannonFire()          → 狮吼炮发射
  5. WindCannon::windCannonFire()  → 风来炮稳定船身
```

## 关键代码

```cpp
class LionCannon {  // Facade - 外观类
public:
    void aimAndLock() {       // 对外: 一步"瞄准"
        m_coke->immitCoke();  // 对内: 三步操作
        m_energy->energyConvert();
        m_aimLock->aimLock();
    }
private:
    CokeSystem* m_coke;       // 持有所有子系统
    EnergySystem* m_energy;
    AimLockSystem* m_aimLock;
    Cannon* m_cannon;
    WindCannon* m_windCannon;
};
```

## 符合设计原则

- **迪米特法则** (最少知识原则): 客户端只与Facade交互，不直接接触子系统
- **单一职责**: Facade负责协调，子系统负责具体功能

## 相关模式对比

| 模式 | 意图 | 方向 |
|------|------|------|
| 外观 | 简化接口，封装复杂性 | 自上而下 |
| 适配器 | 转换不兼容接口 | 横向适配 |
| 代理 | 控制访问 | 一对一代理 |
| 中介者 | 协调多对象交互 | 星形通信 |
