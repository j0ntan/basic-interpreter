#include "Print.hpp"
#include <Expressions/Numeric/NumericExpression.hpp>

Print::Print(unsigned int line_number, const NumericExpression *expression)
    : Command(line_number), expression{expression} {}

std::string Print::format() const {
  return std::to_string(line_num) + " PRINT " + expression->format();
}
