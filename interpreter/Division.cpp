#include "Division.h"

Division::Division(const NumericExpression &nexp1,
                   const NumericExpression &nexp2)
    : BinaryExpression(nexp1, nexp2, '/') {}

int Division::value() const { return -1; }
