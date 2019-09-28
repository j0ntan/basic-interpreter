#include "End.h"
#include <gtest/gtest.h>

TEST(End, createSimpleEnd) {
  const unsigned int line_number = 123;
  const End e(line_number);
}

TEST(End, matchGivenLineNumber) {
  const unsigned int line_number = 123;
  const End e(line_number);
  ASSERT_EQ(e.line(), line_number);
}

TEST(End, format) {
  const unsigned int line_number = 123;
  const End e(line_number);
  ASSERT_EQ(e.format(), "123 END");
}
