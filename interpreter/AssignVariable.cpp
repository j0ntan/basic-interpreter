#include "AssignVariable.h"

AssignVariable::AssignVariable(unsigned int line_number, Variable v,
                               const NumericExpression &value)
    : Command{line_number} {}

std::string AssignVariable::format() const { return std::string(); }
