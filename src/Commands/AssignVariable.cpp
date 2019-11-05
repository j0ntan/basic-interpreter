#include "AssignVariable.hpp"
#include <Expressions/Numeric/Variable.hpp>

AssignVariable::AssignVariable(unsigned int line_number,
                               const Variable *variable,
                               const NumericExpression *value)
    : Command{line_number}, variable{variable}, value{value} {}

std::string AssignVariable::format() const {
  return std::to_string(line_num) + " LET " + variable->format() + ' ' +
         value->format();
}
