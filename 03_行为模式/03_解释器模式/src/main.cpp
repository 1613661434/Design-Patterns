#include "Expression.hpp"
#include <iostream>

int main() {
    // 构建表达式树：(3 + (5 - 2)) + 7
    auto expr = std::make_unique<AddExpression>(
        std::make_unique<AddExpression>(
            std::make_unique<NumberExpression>(3),
            std::make_unique<SubtractExpression>(
                std::make_unique<NumberExpression>(5),
                std::make_unique<NumberExpression>(2)
            )
        ),
        std::make_unique<NumberExpression>(7)
    );

    std::cout << "Result: " << expr->interpret() << std::endl; // 输出：13
    return 0;
}
