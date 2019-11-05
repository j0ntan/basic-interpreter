#include "GoSub.hpp"
#include <gtest/gtest.h>

TEST(GoSub, createSimpleGoSub) {
  const unsigned int line_number = 123, jline = 456;
  const GoSub gosub(line_number, jline);
}

TEST(GoSub, matchGivenLineNumber) {
  const unsigned int line_number = 123, jline = 456;
  const GoSub gosub(line_number, jline);
  ASSERT_EQ(gosub.line(), line_number);
}

TEST(GoSub, format) {
  const unsigned int line_number = 123, jline = 456;
  const GoSub gosub(line_number, jline);
  ASSERT_EQ(gosub.format(), "123 GOSUB <456>");
}
