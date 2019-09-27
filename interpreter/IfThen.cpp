#include "IfThen.h"

IfThen::IfThen(unsigned int line_number, const BooleanExpression &comparison,
               unsigned int jline)
    : Command{line_number} {}

std::string IfThen::format() const { return std::string(); }
