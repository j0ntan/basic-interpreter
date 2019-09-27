#include "GoSub.h"
#include <gtest/gtest.h>

TEST(GoSub, createSimpleGoSub) {
  const unsigned int line_number = 123, jline = 456;
  GoSub g(line_number, jline);
}

TEST(GoSub, matchGivenLineNumber) {
  const unsigned int line_number = 123, jline = 456;
  GoSub g(line_number, jline);
  ASSERT_EQ(g.line(), line_number);
}

TEST(GoSub, format) {
  const unsigned int line_number = 123, jline = 456;
  GoSub g(line_number, jline);
  ASSERT_EQ(g.format(), "123 GOSUB 456");
}
