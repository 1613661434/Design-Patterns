# 简单工厂模式 速查表

## 一句话总结
通过一个工厂类 + 参数枚举，把对象的创建和使用分离。

## ASCII 结构图

```
    客户端
      │
      │  createSmile(Type::BAT)
      ▼
┌──────────────┐     switch(type)
│ SmileFactory │ ─────────────────────┐
└──────────────┘                      │
                                      ▼
                         ┌──────────────────────┐
                         │ case BAT → new Bat   │
                         │ case LION → new Lion │
                         │ case SHEEP → new Sheep│
                         └──────────────────────┘
                                      │
                                      ▼
                              AbstractSmile* obj
                                      │
                              obj->transform()
                              obj->ability()
```

## 关键代码骨架

```cpp
// 工厂类
class SmileFactory {
public:
    AbstractSmile* createSmile(Type type) {
        switch (type) {
            case Type::SHEEP: return new SheepSmile;
            case Type::LION:  return new LionSmile;
            case Type::BAT:   return new BatSmile;
        }
        return nullptr;
    }
};

// 客户端使用
SmileFactory factory;
AbstractSmile* obj = factory.createSmile(Type::BAT);
obj->transform();
```

## 三大角色
1. **抽象产品** - 定义接口 (`AbstractSmile`)
2. **具体产品** - 实现接口 (`SheepSmile`, `LionSmile`, `BatSmile`)
3. **工厂类** - 根据参数创建产品 (`SmileFactory`)

## 适用/不适用

**适用**:
- 产品类型少且稳定的场景
- 客户端不需要知道具体产品类名
- 创建逻辑简单

**不适用**:
- 产品类型频繁新增 (违反开闭原则)
- 创建逻辑复杂需要扩展的场景
- 需要产品族的场景 (用抽象工厂)
