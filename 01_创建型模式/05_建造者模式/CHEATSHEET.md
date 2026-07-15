# 建造者模式 速查表

## 一句话总结
将复杂对象的**构建过程**与**表示**分离，同样的构建流程可创建不同表示。

## ASCII 结构图

```
  Director (导演)               Builder (建造者)           Product (产品)
  ┌────────────┐               ┌────────────┐            ┌──────────┐
  │ buildSimple │ ──calls──>  │ buildBody  │ ──add──>   │Ship.parts│
  │   Ship()   │               │ buildEngine│            │          │
  └────────────┘               └────────────┘            └──────────┘
        │                            ▲
        │ setBuilder(builder)        │ 继承
        ▼                            │
  使用任意建造者            ┌────────┴────────┐
                           │                 │
                    SunnyBuilder       MerryBuilder
                    (神树+狮吼炮+可乐)  (木材+大炮+蒸汽机)
```

## 构建流程 (以导演类为例)

```
  buildSimpleShip()   →  buildBody()  +  buildEngine()
       ↓                        ↓              ↓
  buildStandardShip() →  buildSimpleShip()  +  buildWeapon()
       ↓
  buildRegalShip()    →  buildStandardShip() +  buildInterior()
```

## 关键代码骨架

```cpp
// 导演类：控制步骤顺序
class Director {
    ShipBuilder* m_builder;
public:
    void setBuilder(ShipBuilder* b) { m_builder = b; }
    void buildFullShip() {
        m_builder->buildBody();
        m_builder->buildWeapon();
        m_builder->buildEngine();
    }
};

// 使用
Director d;
SunnyBuilder builder;
d.setBuilder(&builder);
d.buildFullShip();              // 按标准流程构建
SunnyShip* ship = builder.getSunny();
```

## 四大角色
1. **产品** (`SunnyShip`, `MerryShip`) - 复杂对象
2. **抽象建造者** (`ShipBuilder`) - 声明构建步骤
3. **具体建造者** (`SunnyBuilder`, `MerryBuilder`) - 实现构建步骤
4. **导演** (`Director`) - 控制构建流程

## 适用/不适用

**适用**:
- 复杂对象需要分步骤创建
- 同样的步骤产生不同表示
- 需要隐藏构建细节

**不适用**:
- 产品差异巨大 (步骤不共通)
- 构建过程简单 (不需要)
- 产品没有中间状态
