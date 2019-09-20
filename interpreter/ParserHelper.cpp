#include "ParserHelper.h"

bool isNumericExpression(const std::string &str) { return false; }

static bool contains_only_digits(const std::string &str) {
  return str.find_first_not_of("0123456789") == std::string::npos;
}

bool isInteger(const std::string &str) { return contains_only_digits(str); }
