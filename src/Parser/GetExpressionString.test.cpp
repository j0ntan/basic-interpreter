#include "GetExpressionString.hpp"
#include <gtest/gtest.h>

TEST(GetFirstExpressionStr, canCallFunction) { get_first_expression_str("1"); }

TEST(GetFirstExpressionStr, getStringFromFunction) {
  std::string expression = get_first_expression_str("1");
}

TEST(GetFirstExpressionStr, getInteger) {
  ASSERT_EQ("123", get_first_expression_str("123"));
}

TEST(GetFirstExpressionStr, excludeSecondInteger) {
  ASSERT_EQ("123", get_first_expression_str("123 456"));
}

TEST(GetFirstExpressionStr, getVariableName) {
  ASSERT_EQ("NAME", get_first_expression_str("NAME 123"));
}

TEST(GetFirstExpressionStr, getArrayElement) {
  ASSERT_EQ("X[0]", get_first_expression_str("X[0] 123"));
}
