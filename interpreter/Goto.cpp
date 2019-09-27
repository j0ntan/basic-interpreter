#include "Goto.h"

Goto::Goto(unsigned int line_number, unsigned int jline)
    : Command{line_number}, jline{jline} {}

std::string Goto::format() const {
  return std::to_string(line_num) + " GOTO " + std::to_string(jline);
}
