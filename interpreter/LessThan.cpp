#include "LessThan.h"

LessThan::LessThan(const NumericExpression &nexp1,
                   const NumericExpression &nexp2)
    : BooleanExpression(nexp1, nexp2, '<') {}

bool LessThan::value() const { return false; }
