#pragma once

#include <memory>

// 抽象表达式接口
class Expression {
public:
    virtual ~Expression() = default;
    virtual int interpret() = 0;
};

// 终结符表达式：数字
class NumberExpression : public Expression {
    int value;
public:
    explicit NumberExpression(int v) : value(v) {}
    int interpret() override { return value; }
};

// 非终结符表达式：加法
class AddExpression : public Expression {
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
public:
    AddExpression(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r)
        : left(std::move(l)), right(std::move(r)) {
    }

    int interpret() override {
        return left->interpret() + right->interpret();
    }
};

// 非终结符表达式：减法
class SubtractExpression : public Expression {
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
public:
    SubtractExpression(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r)
        : left(std::move(l)), right(std::move(r)) {
    }

    int interpret() override {
        return left->interpret() - right->interpret();
    }
};
