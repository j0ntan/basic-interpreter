#include "Addition.h"

Addition::Addition(const NumericExpression *left,
                   const NumericExpression *right)
    : BinaryExpression(left, right, '+') {}

int Addition::value() const { return left->value() + right->value(); }
