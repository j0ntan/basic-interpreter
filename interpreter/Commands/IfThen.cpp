#include "IfThen.h"
#include "BooleanExpression.h"

IfThen::IfThen(unsigned int line_number, const BooleanExpression *comparison,
               unsigned int jline)
    : Command{line_number}, comparison{comparison}, jline{jline} {}

std::string IfThen::format() const {
  return std::to_string(line_num) + " IF [" + comparison->format() + "] THEN " +
         std::to_string(jline);
}
