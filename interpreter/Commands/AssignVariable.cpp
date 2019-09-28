#include "AssignVariable.h"

AssignVariable::AssignVariable(unsigned int line_number, const Variable &v,
                               const NumericExpression &value)
    : Command{line_number}, variable{v}, value{value} {}

std::string AssignVariable::format() const {
  return std::to_string(line_num) + " LET " + variable.format() + ' ' +
         value.format();
}
