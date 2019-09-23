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
  return isInteger(clean_str) || isVariable(clean_str);
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

static bool has_brackets(size_t left_bracket_pos, size_t right_bracket_pos) {
  return left_bracket_pos != std::string::npos &&
         right_bracket_pos != std::string::npos;
}

bool isArray(const std::string &str) {
  const size_t left_bracket_pos = str.find('[');
  const size_t right_bracket_pos = str.find(']');

  return has_brackets(left_bracket_pos, right_bracket_pos);
}
