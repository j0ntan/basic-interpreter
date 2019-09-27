#include "AssignArray.h"

AssignArray::AssignArray(unsigned int line_number, const Array &array,
                         const NumericExpression &value)
    : Command{line_number} {}

std::string AssignArray::format() const { return std::string(); }
