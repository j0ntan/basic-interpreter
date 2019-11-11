#include "QueryStringProperties.hpp"

bool has_only_digits(const std::string &str) {
  return str.find_first_not_of("0123456789") == std::string::npos;
}

bool has_only_uppercase_letters(const std::string &str) { return true; }
