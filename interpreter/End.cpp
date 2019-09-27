#include "End.h"

End::End(unsigned int line_number) : Command{line_number} {}

std::string End::format() const { return std::string(); }
