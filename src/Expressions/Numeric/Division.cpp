#include "Division.hpp"

Division::Division(const NumericExpression *left,
                   const NumericExpression *right)
    : BinaryExpression(left, right, '/') {}

int Division::value() const { return left->value() / right->value(); }
