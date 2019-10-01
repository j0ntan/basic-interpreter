#include "Parser.h"
#include <cctype>

std::string findNextExpression(const std::string &cmd) {
  size_t begins = 0, ends = 0;
  if (std::isdigit(cmd[0]) || cmd[0] == '-')
    ends = cmd.find_first_not_of("-0123456789");
  else if (std::isupper(cmd[0]))
    ends = cmd.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  return cmd.substr(begins, ends);
}
