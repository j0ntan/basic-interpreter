#include "AssignArray.h"
#include "Variable.h"

AssignArray::AssignArray(unsigned int line_number, const Variable &name,
                         const NumericExpression &index,
                         const NumericExpression &value)
    : Command{line_number}, name{name}, index{index}, value{value} {}

std::string AssignArray::format() const {
  return std::to_string(line_num) + " LET " + name.format() + '[' +
         index.format() + "] " + value.format();
}
