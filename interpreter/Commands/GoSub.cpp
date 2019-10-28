#include "GoSub.h"

GoSub::GoSub(unsigned int line_number, unsigned int jline)
    : Command{line_number}, jline{jline} {}

std::string GoSub::format() const {
  return std::to_string(line_num) + " GOSUB <" + std::to_string(jline) + '>';
}
