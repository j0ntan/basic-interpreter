#include "Print.h"

Print::Print(unsigned int line_number, const NumericExpression &nexp)
    : Command(0) {}

std::string Print::format() const { return std::string(); }
