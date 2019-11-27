#include "GetExpressionString.hpp"
#include <cctype>

std::string get_first_expression_str(const std::string &str) {
  const char &first_letter = str[0];
  size_t length;
  if (isdigit(first_letter))
    length = str.find_first_not_of("0123456789");
  return str.substr(0, length);
}
