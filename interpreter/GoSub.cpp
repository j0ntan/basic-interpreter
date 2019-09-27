#include "GoSub.h"

GoSub::GoSub(unsigned int line_number, unsigned int jline)
    : Command{line_number} {}

std::string GoSub::format() const { return std::string(); }
