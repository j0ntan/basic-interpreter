#include "Addition.h"

Addition::Addition(const NumericExpression &nexp1,
                   const NumericExpression &nexp2)
    : BinaryExpression(nexp1, nexp2, '+') {}

int Addition::value() const { return num1.value() + num2.value(); }
