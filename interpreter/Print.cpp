#include "Print.h"

Print::Print(unsigned int line_number, const NumericExpression &nexp)
    : Command(line_number) {}

std::string Print::format() const { return std::string(); }
