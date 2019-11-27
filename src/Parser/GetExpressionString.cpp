#include "GetExpressionString.hpp"

std::string get_first_expression_str(const std::string &str) {
  const size_t length = str.find_first_not_of("0123456789");
  return str.substr(0, length);
}
