#include "Parser.h"
#include <cctype>

std::string findNextExpression(const std::string &cmd) {
  size_t begins = 0, ends = 0;
  if (std::isdigit(cmd[0]) || cmd[0] == '-')
    ends = cmd.find_first_not_of("-0123456789");
  else if (std::isupper(cmd[0]))
    ends = cmd.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  else if (cmd[0] == '(') {
    int nested_count = 0;
    do {
      if (cmd[ends] == '(')
        ++nested_count;
      else if (cmd[ends] == ')')
        --nested_count;
    } while (++ends < cmd.size() && nested_count != 0);
  }
  return cmd.substr(begins, ends);
}
