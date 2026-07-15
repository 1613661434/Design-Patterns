# 抽象工厂模式 速查表

## 一句话总结
提供一个接口创建**一系列相关对象**（产品族），无需指定具体类。

## ASCII 结构图

```
    客户端 (选择具体工厂)
         │
         ▼
  AbstractFactory* f = new StandardFactory;
         │
         │  f->createShip()
         ▼
  ┌─────────────────────────────────────────────┐
  │           StandardFactory (具体工厂)         │
  │                                             │
  │  createShip() {                             │
  │    return new Ship(                         │
  │      new IronBody,   ← 同一产品族 (标准型)   │
  │      new Cannon,                            │
  │      new Diesel                             │
  │    );                                       │
  │  }                                          │
  └─────────────────────────────────────────────┘
```

## 产品等级与产品族

```
          ShipBody      Weapon      Engine
            │             │           │
  基础型──WoodBody───────Gun────────Human
  标准型──IronBody──────Cannon─────Diesel
  旗舰型──MetalBody─────Laser──────Nuclear

  横向 = 产品等级 (Product Hierarchy)
  纵向 = 产品族   (Product Family)
```

## 关键代码骨架

```cpp
// 抽象工厂
class AbstractFactory {
public:
    virtual Ship* createShip() = 0;  // 创建整个产品族
};

// 具体工厂：创建一整套相关产品
class StandardFactory : public AbstractFactory {
public:
    Ship* createShip() override {
        return new Ship(
            new IronBody,   // 船体产品族
            new Cannon,     // 武器产品族
            new Diesel      // 动力产品族
        );
    }
};
```

## 产品族成员 (本示例)

| 工厂等级 | 船体 | 武器 | 动力 |
|---------|------|------|------|
| BasicFactory | WoodBody (木材) | Gun (枪) | Human (人力) |
| StandardFactory | IronBody (钢铁) | Cannon (机关炮) | Diesel (内燃机) |
| UltimateFactory | MetalBody (合金) | Laser (激光) | Nuclear (核能) |

## 适用/不适用

**适用**:
- 系统需要一系列配套的产品 (如不同风格的UI组件)
- 需要保证产品族内各产品兼容
- 需要一套产品库同时提供给多个客户端

**不适用**:
- 新增产品等级很频繁 (修改所有工厂)
- 产品族结构不稳定
- 只需要创建单一产品 (用简单工厂/工厂方法)
