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

static bool has_keyword(const std::string &cmd, const std::string &keyword) {
  const auto keyword_pos = cmd.find(keyword);
  const auto found_keyword = keyword_pos != std::string::npos;
  const auto has_left_whitespace =
      found_keyword &&
      cmd.find_last_of(" \t", keyword_pos - 1) == keyword_pos - 1;
  const auto has_right_whitespace =
      found_keyword &&
      cmd.find_first_of(" \t", keyword_pos + keyword.length()) ==
          keyword_pos + keyword.length();
  return found_keyword && has_left_whitespace && has_right_whitespace;
}

bool is_print_cmd(const std::string &cmd) {
  const auto print_pos = cmd.find("PRINT");
  const auto has_print_keyword = print_pos != std::string::npos;
  if (has_keyword(cmd, "PRINT")) {
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

bool is_assign_variable_cmd(const std::string &cmd) {
  const auto let_pos = cmd.find("LET");
  const auto has_let_keyword = let_pos != std::string::npos;
  if (has_keyword(cmd, "LET")) {
    const auto before_let_pos = let_pos - 1;
    const auto after_let_pos = let_pos + 3;
    const auto has_whitespace_around_let =
        cmd.find_last_of(" \t", before_let_pos) == before_let_pos &&
        cmd.find_first_of(" \t", after_let_pos) == after_let_pos;
    const auto variable_begins_pos =
        cmd.find_first_not_of(" \t", after_let_pos);
    const auto variable_ends_pos =
        cmd.find_first_of(" \t", variable_begins_pos);
    const auto variable = cmd.substr(variable_begins_pos,
                                     variable_ends_pos - variable_begins_pos),
               value = cmd.substr(variable_ends_pos);
    return has_whitespace_around_let && !variable.empty() &&
           isVariable(variable) && !value.empty() && isNumericExpression(value);
  }
  return false;
}

size_t find_matching_bracket(size_t left_bracket_pos, const std::string &cmd) {
  for (size_t i = left_bracket_pos, nested_count = 0; i < cmd.size(); ++i) {
    const auto &this_char = cmd[i];
    if (this_char == '[' || this_char == '(')
      ++nested_count;
    else if (this_char == ']' || this_char == ')')
      --nested_count;
    if (nested_count == 0)
      return i;
  }
  return std::string::npos;
}

bool is_assign_array_cmd(const std::string &cmd) {
  const auto let_pos = cmd.find("LET");
  const auto has_let_keyword = let_pos != std::string::npos;
  const auto left_bracket_pos = cmd.find('[');
  const auto right_bracket_pos = find_matching_bracket(left_bracket_pos, cmd);
  const auto has_bracket_pair = left_bracket_pos != std::string::npos &&
                                right_bracket_pos != std::string::npos;
  if (has_keyword(cmd, "LET") && has_bracket_pair) {
    const auto before_let_pos = let_pos - 1;
    const auto after_let_pos = let_pos + 3;
    const auto has_whitespace_around_let =
        cmd.find_last_of(" \t", before_let_pos) == before_let_pos &&
        cmd.find_first_of(" \t", after_let_pos) == after_let_pos;
    const auto variable = findNextExpression(cmd.substr(after_let_pos));
    const auto index = cmd.substr(left_bracket_pos + 1,
                                  right_bracket_pos - left_bracket_pos - 1);
    const auto value = cmd.substr(right_bracket_pos + 1);
    return has_whitespace_around_let && !variable.empty() &&
           isVariable(variable) && !index.empty() &&
           isNumericExpression(index) && !value.empty() &&
           isNumericExpression(value);
  }
  return false;
}

bool is_goto_cmd(const std::string &cmd) {
  const auto goto_pos = cmd.find("GOTO");
  const auto found_goto = goto_pos != std::string::npos;
  const auto has_left_whitespace =
      found_goto && cmd.find_last_of(" \t", goto_pos - 1) == goto_pos - 1;
  const auto has_right_whitespace =
      found_goto && cmd.find_last_of(" \t", goto_pos + 4) == goto_pos + 4;
  const auto has_goto_keyword =
      found_goto && has_left_whitespace && has_right_whitespace;
  if (has_keyword(cmd, "GOTO")) {
    const auto jline = findNextExpression(cmd.substr(goto_pos + 4));
    return !jline.empty() && isInteger(jline) && jline[0] != '-';
  }
  return false;
}

bool is_if_then_cmd(const std::string &cmd) {
  const auto if_pos = cmd.find("IF"), then_pos = cmd.find("THEN");
  const auto found_if = if_pos != std::string::npos,
             found_then = then_pos != std::string::npos;
  const auto has_left_whitespace =
      found_if && found_then &&
      cmd.find_last_of(" \t", if_pos - 1) == if_pos - 1 &&
      cmd.find_last_of(" \t", then_pos - 1) == then_pos - 1;
  const auto has_right_whitespace =
      found_if && found_then &&
      cmd.find_first_of(" \t", if_pos + 2) == if_pos + 2 &&
      cmd.find_first_of(" \t", then_pos + 4) == then_pos + 4;
  const auto has_keywords =
      found_if && found_then && has_left_whitespace && has_right_whitespace;
  if (has_keyword(cmd, "IF") && has_keyword(cmd, "THEN") && if_pos < then_pos) {
    const auto boolean_begins_pos = cmd.find_first_not_of(" \t", if_pos + 2),
               boolean_ends_pos = cmd.find_last_not_of(" \t", then_pos - 1);
    const auto has_boolean_expression = boolean_begins_pos < boolean_ends_pos;
    const auto boolean =
        has_boolean_expression
            ? cmd.substr(boolean_begins_pos,
                         boolean_ends_pos - boolean_begins_pos + 1)
            : std::string();
    const auto jline = findNextExpression(cmd.substr(then_pos + 4));
    return isBooleanExpression(boolean) && !jline.empty() && isInteger(jline) &&
           jline[0] != '-';
  }
  return false;
}

bool is_gosub_cmd(const std::string &cmd) {
  const auto gosub_pos = cmd.find("GOSUB");
  const auto found_gosub = gosub_pos != std::string::npos;
  const auto has_left_whitespace =
      found_gosub && cmd.find_last_of(" \t", gosub_pos - 1) == gosub_pos - 1;
  const auto has_right_whitespace =
      found_gosub && cmd.find_last_of(" \t", gosub_pos + 5) == gosub_pos + 5;
  const auto has_gosub_keyword =
      found_gosub && has_left_whitespace && has_right_whitespace;
  if (has_keyword(cmd, "GOSUB")) {
    const auto jline = findNextExpression(cmd.substr(gosub_pos + 5));
    return !jline.empty() && isInteger(jline) && jline[0] != '-';
  }
  return false;
}

bool is_return_cmd(const std::string &cmd) {
  const auto return_pos = cmd.find("RETURN");
  const auto found_return = return_pos != std::string::npos;
  const auto has_left_whitespace =
      found_return && cmd.find_last_of(" \t", return_pos - 1) == return_pos - 1;
  const auto is_end_of_cmd = return_pos + 6 == cmd.length();
  const auto has_return_keyword =
      found_return && has_left_whitespace && is_end_of_cmd;
  return has_return_keyword;
}

bool is_end_cmd(const std::string &cmd) {
  const auto end_pos = cmd.find("END");
  const auto found_end = end_pos != std::string::npos;
  const auto has_left_whitespace =
      found_end && cmd.find_last_of(" \t", end_pos - 1) == end_pos - 1;
  const auto is_end_of_cmd = end_pos + 3 == cmd.length();
  const auto has_end_keyword =
      found_end && has_left_whitespace && is_end_of_cmd;
  return has_end_keyword;
}
