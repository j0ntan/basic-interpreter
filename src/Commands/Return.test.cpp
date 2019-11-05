#include "Return.hpp"
#include <gtest/gtest.h>

TEST(Return, createSimpleReturn) {
  const unsigned int line_number = 123;
  Return return_cmd(line_number);
}

TEST(Return, matchGivenLineNumber) {
  const unsigned int line_number = 123;
  Return return_cmd(line_number);
  ASSERT_EQ(return_cmd.line(), line_number);
}

TEST(Return, format) {
  const unsigned int line_number = 123;
  Return return_cmd(line_number);
  ASSERT_EQ(return_cmd.format(), "123 RETURN");
}
