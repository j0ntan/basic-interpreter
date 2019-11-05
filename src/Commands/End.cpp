#include "End.hpp"

End::End(unsigned int line_number) : Command{line_number} {}

std::string End::format() const { return std::to_string(line_num) + " END"; }
