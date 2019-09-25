#include "Print.h"

Print::Print(unsigned int line_number, const NumericExpression &nexp)
    : num{nexp}, Command(line_number) {}

std::string Print::format() const {
  return std::to_string(line_num) + " PRINT " + num.format();
}
