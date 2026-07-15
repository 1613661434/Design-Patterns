# 解释器模式 - 快速参考

## ASCII 结构图

```
表达式: (3 + (5 - 2)) + 7

表达式树:
                  ┌──────────────┐
                  │ AddExpression│         ← 根节点 (+)
                  └──┬────────┬──┘
                     │        │
        ┌────────────▼──┐     ▼
        │ AddExpression │  NumberExpression
        └──┬────────┬───┘     (7)
           │        │
     ┌─────▼──┐  ┌──▼──────────────┐
     │Number  │  │SubtractExpression│
     │Expr(3) │  └──┬──────────┬────┘
     └────────┘     │          │
              ┌──────▼──┐ ┌─────▼──┐
              │Number   │ │Number  │
              │Expr(5)  │ │Expr(2) │
              └─────────┘ └────────┘
```

## 关键参与者

| 类 | 职责 | 类型 |
|----|------|------|
| `Expression` | 抽象表达式接口 | `interpret()` 纯虚函数 |
| `NumberExpression` | 终结符：数字 | 返回自身 value |
| `AddExpression` | 非终结符：加法 | 返回 left + right |
| `SubtractExpression` | 非终结符：减法 | 返回 left - right |

## 调用流程

```
interpret() 递归调用:
  AddExpr.interpret()
    -> AddExpr.interpret()
      -> NumberExpr(3).interpret() => 3
      -> SubtractExpr.interpret()
        -> NumberExpr(5).interpret() => 5
        -> NumberExpr(2).interpret() => 2
        => 5 - 2 = 3
    => 3 + 3 = 6
    -> NumberExpr(7).interpret() => 7
  => 6 + 7 = 13
```

## 何时使用

- 有简单的文法需要解释执行
- 语法规则稳定，类数量可控（通常 < 10-15 个规则）
- 不需要太高的执行效率
- 表达式求值、规则引擎、简单脚本语言

## 编译与运行

```bash
make
./main
```
