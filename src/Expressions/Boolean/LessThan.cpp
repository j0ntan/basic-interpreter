#include <Expressions/Boolean/LessThan.hpp>

LessThan::LessThan(const NumericExpression *left,
                   const NumericExpression *right)
    : BooleanExpression(left, right, '<') {}

bool LessThan::value() const { return left->value() < right->value(); }
