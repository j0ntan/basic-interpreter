#include "AssignArray.h"

AssignArray::AssignArray(unsigned int line_number, const Array &array,
                         const NumericExpression &value)
    : Command{line_number}, array{array}, value{value} {}

std::string AssignArray::format() const {
  return std::to_string(line_num) + " LET " + array.format() + ' ' +
         value.format();
}
