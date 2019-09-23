#include "ParserHelper.h"

static std::string remove_leading_whitespace(const std::string &str) {
  return str.substr(str.find_first_not_of(" \t"));
}

static std::string remove_trailing_whitespace(const std::string &str) {
  return str.substr(0, str.find_last_not_of(" \t") + 1);
}

static std::string remove_surrounding_whitespace(const std::string &str) {
  std::string clean_str = str;

  const bool has_leading_whitespace = str.find_first_of(" \t") == 0;
  if (has_leading_whitespace)
    clean_str = remove_leading_whitespace(clean_str);

  const bool has_trailing_whitespace =
      str.find_last_of(" \t") == str.length() - 1;
  if (has_trailing_whitespace)
    clean_str = remove_trailing_whitespace(clean_str);

  return clean_str;
}

static bool has_no_digits_or_uppercase_letters(const std::string &str) {
  return str.find_first_of("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
         std::string::npos;
}

bool isNumericExpression(const std::string &str) {
  if (has_no_digits_or_uppercase_letters(str))
    return false;

  const std::string clean_str = remove_surrounding_whitespace(str);
  return isInteger(clean_str) || isVariable(clean_str) || isArray(clean_str);
}

static bool first_char_is_negative_or_digit(const std::string &str) {
  return str[0] == '-' || str.find_first_of("0123456789") == 0;
}

static bool remaining_chars_only_digits(const std::string &str) {
  return str.find_first_not_of("0123456789", 1) == std::string::npos;
  ;
}

bool isInteger(const std::string &str) {
  return first_char_is_negative_or_digit(str) &&
         remaining_chars_only_digits(str);
}

static bool has_only_uppercase_letters(const std::string &str) {
  return str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
         std::string::npos;
}

static bool does_not_match_keyword(const std::string &str) {
  return str != "PRINT" && str != "LET" && str != "GOTO" && str != "IF" &&
         str != "THEN" && str != "GOSUB" && str != "RETURN" && str != "END";
}

bool isVariable(const std::string &str) {
  return str.length() <= 8 && has_only_uppercase_letters(str) &&
         does_not_match_keyword(str);
}

static bool missing_bracket(size_t left_bracket_pos, size_t right_bracket_pos) {
  return left_bracket_pos == std::string::npos ||
         right_bracket_pos == std::string::npos;
}

static bool brackets_not_ordered(size_t left_bracket_pos,
                                 size_t right_bracket_pos) {
  return left_bracket_pos > right_bracket_pos;
}

static std::string array_index(const std::string &str, size_t left_bracket_pos,
                               size_t right_bracket_pos) {
  const std::string index_with_whitespace = str.substr(
      left_bracket_pos + 1, right_bracket_pos - left_bracket_pos - 1);
  return remove_surrounding_whitespace(index_with_whitespace);
}

static std::string array_name(const std::string &str, size_t left_bracket_pos) {
  const std::string name_with_whitespace = str.substr(0, left_bracket_pos);
  return remove_trailing_whitespace(name_with_whitespace);
}

static bool index_is_positive(const std::string &index) {
  return index[0] != '-';
}

bool isArray(const std::string &str) {
  const size_t left_bracket_pos = str.find_first_of('[');
  const size_t right_bracket_pos = str.find_last_of(']');

  if (missing_bracket(left_bracket_pos, right_bracket_pos) ||
      brackets_not_ordered(left_bracket_pos, right_bracket_pos))
    return false;

  const std::string name = array_name(str, left_bracket_pos);
  const std::string index =
      array_index(str, left_bracket_pos, right_bracket_pos);
  const bool index_is_int = isInteger(index);

  return !name.empty() && !index.empty() && isVariable(name) &&
         ((index_is_int && index_is_positive(index)) ||
          (!index_is_int && isNumericExpression(index)));
}

static bool has_enclosing_parenthesis(const std::string &str) {
  return str.front() == '(' && str.back() == ')';
}

static unsigned int count_operators(const std::string &operands) {
  unsigned int count = 0;
  for (int i = 0; i < operands.size(); ++i) {
    const char this_char = operands[i];

    if (this_char == '+' || this_char == '-' || this_char == '*' ||
        this_char == '/') {
      const bool has_preceding_num =
          (i - 1) >= 0 && operands.find_last_of("0123456789", i - 1) == (i - 1);
      const bool has_proceeding_num =
          (i + 1) < operands.size() &&
          operands.find_first_of("0123456789", i + 1) == (i + 1);

      if (has_preceding_num && has_proceeding_num)
        ++count;
    }
  }
  return count;
}

bool isBinaryExpression(const std::string &str) {
  if (!has_enclosing_parenthesis(str))
    return false;

  const std::string operands = str.substr(1, str.length() - 2);

  return !operands.empty() && count_operators(operands) == 1;
}
