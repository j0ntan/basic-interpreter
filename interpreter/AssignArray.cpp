#include "AssignArray.h"

AssignArray::AssignArray(unsigned int line_number, const Array &array,
                         const NumericExpression &value)
    : Command{0} {}

std::string AssignArray::format() const { return std::string(); }
