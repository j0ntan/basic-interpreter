#include "Print.h"
#include "NumericExpression.h"

Print::Print(unsigned int line_number, const NumericExpression *expression)
    : expression{expression}, Command(line_number) {}

std::string Print::format() const {
  return std::to_string(line_num) + " PRINT " + expression->format();
}
