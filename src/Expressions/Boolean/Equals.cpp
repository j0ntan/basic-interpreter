#include <Expressions/Boolean/Equals.hpp>

Equals::Equals(const NumericExpression *left, const NumericExpression *right)
    : BooleanExpression(left, right, '=') {}

bool Equals::value() const { return left->value() == right->value(); }
