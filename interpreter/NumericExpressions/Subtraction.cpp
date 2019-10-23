#include "Subtraction.h"

Subtraction::Subtraction(const NumericExpression *left,
                         const NumericExpression *right)
    : BinaryExpression(left, right, '-') {}

int Subtraction::value() const { return left->value() - right->value(); }
