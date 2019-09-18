#include "Multiplication.h"

Multiplication::Multiplication(const NumericExpression &nexp1,
                               const NumericExpression &nexp2)
    : BinaryExpression(nexp1, nexp2, '*') {}

int Multiplication::value() const { return num1.value() * num2.value(); }
