# 工厂方法模式 速查表

## 一句话总结
定义创建对象的接口，让子类决定 new 哪个具体类。

## ASCII 结构图

```
  客户端选择具体工厂
        │
        ▼
  AbstractFactory* factory = new BatFactory;
        │
        │  factory->createSmile()
        ▼
  ┌─────────────┐     创建      ┌──────────────┐
  │  BatFactory  │ ────────────>│  BatSmile     │
  │  (具体工厂)   │              │  (具体产品)    │
  └─────────────┘              └──────────────┘
        ↑                            ↑
        │ 继承                       │ 继承
  ┌─────────────┐              ┌──────────────┐
  │AbstractFact │              │AbstractSmile │
  │ (抽象工厂)   │              │ (抽象产品)    │
  └─────────────┘              └──────────────┘
```

## 关键代码骨架

```cpp
// 抽象工厂
class AbstractFactory {
public:
    virtual AbstractSmile* createSmile() = 0; // 工厂方法
};

// 具体工厂: 1产品 = 1工厂
class BatFactory : public AbstractFactory {
public:
    AbstractSmile* createSmile() override {
        return new BatSmile;  // 子类决定创建哪个产品
    }
};

// 使用
AbstractFactory* f = new BatFactory;
AbstractSmile* obj = f->createSmile();
```

## 四大角色
1. **抽象产品** (`AbstractSmile`) - 纯虚接口
2. **具体产品** (`SheepSmile`, `LionSmile`, `BatSmile`)
3. **抽象工厂** (`AbstractFactory`) - `createSmile() = 0`
4. **具体工厂** (`SheepFactory`, `LionFactory`, `BatFactory`)

## 核心原则
- 「开闭原则」: 对扩展开放 (添加新工厂)、对修改关闭 (不改旧代码)
- 「依赖倒置」: 客户端依赖抽象工厂接口，不依赖具体工厂

## 适用/不适用

**适用**:
- 产品类频繁新增
- 需要解耦产品创建和使用
- 系统需要灵活选择创建哪种产品

**不适用**:
- 产品种类极少且不会变化 (过度设计)
- 产品创建逻辑简单 (不需要工厂)
- 需要创建产品族 (考虑抽象工厂)
