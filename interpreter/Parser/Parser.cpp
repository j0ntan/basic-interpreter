#include "Parser.h"
#include "ParserHelper.h"
#include <cctype>

std::string findNextExpression(const std::string &cmd) {
  size_t offset = cmd.find_first_not_of(" \t");
  size_t begins = offset == std::string::npos ? 0 : offset, ends = begins;

  if (std::isdigit(cmd[begins]) || cmd[begins] == '-')
    ends = cmd.find_first_not_of("-0123456789", begins);
  else if (std::isupper(cmd[begins]))
    ends = cmd.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ", begins);
  else if (cmd[begins] == '(') {
    int nested_count = 0;
    do {
      if (cmd[ends] == '(')
        ++nested_count;
      else if (cmd[ends] == ')')
        --nested_count;
    } while (++ends < cmd.size() && nested_count != 0);
  }
  return cmd.substr(begins, ends - begins);
}

bool has_line_number(const std::string &cmd) {
  const size_t non_whitespace_pos = cmd.find_first_not_of(" \t");
  return cmd.find_first_of("0123456789", non_whitespace_pos) ==
         non_whitespace_pos;
}

bool is_print_cmd(const std::string &cmd) {
  const auto print_pos = cmd.find("PRINT");
  const auto has_print_keyword = print_pos != std::string::npos;
  if (has_print_keyword) {
    const auto before_print_pos = print_pos - 1;
    const auto after_print_pos = print_pos + 5;
    const auto has_whitespace_around_print =
        cmd.find_last_of(" \t", before_print_pos) == before_print_pos &&
        cmd.find_first_of(" \t", after_print_pos) == after_print_pos;
    const auto value = cmd.substr(after_print_pos);
    return has_whitespace_around_print && isNumericExpression(value);
  }
  return false;
}
