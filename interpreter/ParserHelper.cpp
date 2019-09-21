#include "ParserHelper.h"

static std::string remove_leading_whitespace(const std::string &str) {
  return str.substr(str.find_first_of("-0123456789"));
}

bool isNumericExpression(const std::string &str) {
  std::string clean_str = str;

  const bool has_leading_whitespace = str.find_first_of(" \t") == 0;
  if (has_leading_whitespace)
    clean_str = remove_leading_whitespace(clean_str);

  return isInteger(clean_str);
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
