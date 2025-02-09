#include "ParserHelper.h"

std::string remove_surrounding_whitespace(const std::string &str) {
  const size_t first_char = str.find_first_not_of(" \t");
  const size_t last_char = str.find_last_not_of(" \t");
  if (str.empty() || (first_char == 0 && last_char == str.size() - 1))
    return str;
  else if (first_char == std::string::npos)
    return std::string();
  return str.substr(first_char, last_char - first_char + 1);
}

static bool has_no_digits_or_uppercase_letters(const std::string &str) {
  return str.find_first_of("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
         std::string::npos;
}

bool isNumericExpression(const std::string &str) {
  if (has_no_digits_or_uppercase_letters(str))
    return false;

  const std::string clean_str = remove_surrounding_whitespace(str);
  return isInteger(clean_str) || isVariable(clean_str) || isArray(clean_str) ||
         isBinaryExpression(clean_str);
}

static bool first_char_is_negative_or_digit(const std::string &str) {
  return str[0] == '-' || str.find_first_of("0123456789") == 0;
}

static bool remaining_chars_only_digits(const std::string &str) {
  return str.find_first_not_of("0123456789", 1) == std::string::npos;
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
  return remove_surrounding_whitespace(name_with_whitespace);
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

static bool has_valid_operands(const std::string &expression) {
  const auto operands = get_operands(expression);
  const auto &left_operand = operands.first;
  const auto &right_operand = operands.second;
  return !left_operand.empty() && !right_operand.empty() &&
         isNumericExpression(left_operand) &&
         isNumericExpression(right_operand);
}

bool isBinaryExpression(const std::string &str) {
  if (!has_enclosing_parenthesis(str))
    return false;

  const std::string expression = str.substr(1, str.length() - 2);

  return !expression.empty() && has_valid_operands(expression);
}

bool isBooleanExpression(const std::string &str) {
  const auto less_than_pos = str.find('<'), greater_than_pos = str.find('>'),
             equals_pos = str.find('=');
  const auto compare_less_than = less_than_pos != std::string::npos;
  const auto compare_greater_than = greater_than_pos != std::string::npos;
  const auto compare_equals = equals_pos != std::string::npos;
  if (compare_less_than || compare_greater_than || compare_equals) {
    const auto operands = get_operands(str);
    return isNumericExpression(operands.first) &&
           isNumericExpression(operands.second);
  }
  return false;
}

std::pair<std::string, std::string>
get_operands(const std::string &expression) {
  size_t operator_position = 0;
  for (size_t i = 0, nested_count = 0;
       i < expression.size() && operator_position == 0; ++i) {
    const char &this_char = expression[i];
    if (nested_count == 0 &&
        (this_char == '+' || (this_char == '-' && i != 0) || this_char == '*' ||
         this_char == '/' || this_char == '<' || this_char == '>' ||
         this_char == '='))
      operator_position = i;
    else if (this_char == '(')
      ++nested_count;
    else if (this_char == ')')
      --nested_count;
  }
  return std::make_pair(expression.substr(0, operator_position),
                        expression.substr(operator_position + 1));
}
