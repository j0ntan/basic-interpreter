#include "GetExpressionString.hpp"
#include <gtest/gtest.h>

TEST(GetFirstExpressionStr, canCallFunction) { get_first_expression_str("1"); }

TEST(GetFirstExpressionStr, getStringFromFunction) {
  std::string expression = get_first_expression_str("1");
}
