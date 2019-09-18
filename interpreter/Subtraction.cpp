#include "Subtraction.h"

Subtraction::Subtraction(const NumericExpression &nexp1,
                         const NumericExpression &nexp2)
    : BinaryExpression(nexp1, nexp2, '-') {}

int Subtraction::value() const { return num1.value() - num2.value(); }
