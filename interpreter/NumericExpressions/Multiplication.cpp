#include "Multiplication.h"

Multiplication::Multiplication(const NumericExpression *left,
                               const NumericExpression *right)
    : BinaryExpression(left, right, '*') {}

int Multiplication::value() const { return left->value() * right->value(); }
