#include "Equals.h"

Equals::Equals(const NumericExpression &nexp1, const NumericExpression &nexp2)
    : BooleanExpression(nexp1, nexp2, '=') {}

bool Equals::value() const { return false; }
