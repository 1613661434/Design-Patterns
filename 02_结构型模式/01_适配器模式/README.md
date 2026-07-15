# 适配器模式 (Adapter Pattern)

## 一、模式意图 (Intent)

将一个类的接口转换成客户端期望的另一个接口，使原本因接口不兼容而无法一起工作的类可以协同工作。

## 二、模式结构 (Structure)

```
┌─────────────┐          ┌──────────────────┐          ┌─────────────┐
│   Client    │ ───────> │  AbstractChopper │          │  Foreigner  │
│  (main.cpp) │          │    (Adapter)     │────────> │  (Adaptee)  │
└─────────────┘          └────────┬─────────┘          └──────┬──────┘
                                  │                           │
                    ┌─────────────┼─────────────┐    ┌───────┼───────┐
                    │             │             │    │       │       │
              EnglishChopper FrenchChopper     Panda  American  French
              (Concrete        (Concrete    (Target)
               Adapter)        Adapter)                  (Concrete Adaptees)
```

| 角色 | 类名 | 说明 |
|------|------|------|
| Target（目标接口） | Panda | 客户端期望使用的接口（大熊猫的消息接口） |
| Adaptee（适配者） | Foreigner, American, French | 需要被适配的现有接口（外国人及其子类） |
| Adapter（适配器） | AbstractChopper | 连接Target和Adaptee的中间类 |
| ConcreteAdapter | EnglishChopper, FrenchChopper | 具体适配器，实现翻译逻辑 |
| Client（客户端） | main.cpp | 通过适配器使用Target接口 |

## 三、示例场景 (海贼王主题)

**乔巴翻译官**: 熊猫只能理解特定格式的消息，而外国人（美国人、法国人）使用不同的语言接口。乔巴（适配器）作为翻译官，将各种外国人的"忏悔"翻译成熊猫能理解的语言，同时将熊猫的回应翻译给相应的外国人。

- `Foreigner` / `American` / `French`: 外国人的"忏悔"接口
- `Panda`: 熊猫的消息接收与响应接口
- `EnglishChopper`: 英语翻译官，连接Panda与American
- `FrenchChopper`: 法语翻译官，连接Panda与French

## 四、优缺点

### 优点
1. **单一职责原则**: 将接口转换逻辑与业务逻辑分离
2. **开闭原则**: 新增适配器类无需修改现有代码
3. **提高复用性**: 可以复用现有的类，无需修改其源码

### 缺点
1. 增加了系统的复杂度，需要引入额外的适配器类
2. 过多的适配器会使系统变得凌乱

## 五、适用场景

- 需要使用现有的类，但其接口不符合需求
- 想创建一个可复用的类，该类能与多个不相关的类协同工作
- 需要统一多个不同接口的场景
