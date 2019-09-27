#include "Goto.h"

Goto::Goto(unsigned int line_number, unsigned int jline)
    : Command{line_number} {}

std::string Goto::format() const { return std::string(); }
