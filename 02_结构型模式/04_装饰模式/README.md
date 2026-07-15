# 装饰模式 (Decorator Pattern)

## 一、模式意图 (Intent)

在不修改原有对象结构的前提下，**动态地为对象添加新的功能**。该模式通过创建一个包装对象（装饰器）来包裹原始对象，使客户端可以像使用原始对象一样使用装饰后的对象，同时获得额外的功能。

## 二、模式结构 (Structure)

```
┌──────────────────────┐
│      Soldier         │  <-- Component (抽象组件)
│  + getName() = 0     │
│  + fight() = 0       │
└──────────┬───────────┘
           │
  ┌────────┴────────────────────┐
  │                             │
┌─┴─────────────────┐  ┌───────┴──────────────────┐
│      Teach        │  │  DevilFruitDecorator     │  <-- Decorator (抽象装饰器)
│  (Concrete         │  │  - soldier: unique_ptr   │
│   Component)       │  │  + getName()             │
│  黑胡子的体术       │  │  + fight() = 0 (不实现)   │
└───────────────────┘  └───────────┬──────────────┘
                                   │
                    ┌──────────────┼──────────────┐
                    │              │              │
             DarkFruit       QuakeFruit       PieFruit
             (暗暗果实)       (震震果实)       (大饼果实)
```

| 角色 | 类名 | 说明 |
|------|------|------|
| Component（抽象组件） | Soldier | 定义战士的基本接口 |
| ConcreteComponent（具体组件） | Teach | 黑胡子，拥有体术战斗能力 |
| Decorator（抽象装饰器） | DevilFruitDecorator | 持有Component引用，接口一致 |
| ConcreteDecorator（具体装饰器） | DarkFruit, QuakeFruit, PieFruit | 各种恶魔果实能力 |

## 三、示例场景 (海贼王主题)

**黑胡子的恶魔果实**: 黑胡子（Teach）依靠体术战斗。通过装饰模式，动态为他添加多个恶魔果实能力：
- `DarkFruit`: 暗暗果实 -- 黑洞吸引力
- `QuakeFruit`: 震震果实 -- 引发震动
- `PieFruit`: 大饼果实 -- 大饼铠甲与回血

每个装饰器在调用 `fight()` 时先执行内层逻辑，再叠加自己的新能力。

## 四、优缺点

### 优点
1. **开闭原则**: 无需修改原有类即可扩展功能
2. **灵活性**: 可以动态组合多个装饰器，运行时决定功能组合
3. **单一职责**: 每个装饰器只关注一个附加功能
4. **优于继承**: 避免为每种组合创建子类的类爆炸问题

### 缺点
1. 装饰器链过长时会增加系统复杂度
2. 装饰器数量过多会产生很多小类
3. 装饰器链中的对象移除较困难
4. 首次调用时的初始化行为可能需要注意

## 五、适用场景

- 需要动态、透明地给对象添加功能（可撤销）
- 无法通过继承扩展功能（如final类）
- 需要组合多个可选功能，且组合方式不确定
- 与继承对比：继承是静态的，装饰是动态的

## 六、智能指针的使用

本例使用 `std::unique_ptr<Soldier>` 管理装饰链，避免了原始指针的内存泄漏问题。每个装饰器"拥有"其包装的对象，形成所有权链：

```cpp
unique_ptr<Soldier> teach = make_unique<Teach>("黑胡子");
teach = make_unique<DarkFruit>(move(teach));   // DarkFruit拥有Teach
teach = make_unique<QuakeFruit>(move(teach));  // QuakeFruit拥有DarkFruit
// 离开作用域时自动释放整条链
```
