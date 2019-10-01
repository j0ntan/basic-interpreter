#include "Parser.h"
#include <cctype>

std::string findNextExpression(const std::string &cmd) {
  size_t begins = 0;
  while (begins < cmd.size() &&
         !(std::isdigit(cmd[begins]) || cmd[begins] == '-' ||
           std::isupper(cmd[begins])))
    ++begins;
  size_t ends = begins + 1;
  while (ends < cmd.size() &&
         (std::isdigit(cmd[ends]) || std::isupper(cmd[ends])))
    ++ends;
  return cmd.substr(begins, ends);
}
