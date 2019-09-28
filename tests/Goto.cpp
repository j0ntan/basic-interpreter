#include "Goto.h"
#include <gtest/gtest.h>

TEST(Goto, createSimpleGoto) {
  const unsigned int line_number = 123, jline = 456;
  const Goto g(line_number, jline);
}

TEST(Goto, matchGivenLineNumber) {
  const unsigned int line_number = 15, jline = 23;
  const Goto g(line_number, jline);
  ASSERT_EQ(g.line(), line_number);
}

TEST(Goto, format) {
  const unsigned int line_number = 15, jline = 23;
  const Goto g(line_number, jline);
  ASSERT_EQ(g.format(), "15 GOTO 23");
}
