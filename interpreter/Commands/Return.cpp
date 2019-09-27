#include "Return.h"

Return::Return(unsigned int line_number) : Command{line_number} {}

std::string Return::format() const {
  return std::to_string(line_num) + " RETURN";
}
