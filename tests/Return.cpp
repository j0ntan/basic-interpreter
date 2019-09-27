#include "Return.h"
#include <gtest/gtest.h>

TEST(Return, createSimpleReturn) {
  const unsigned int line_number = 123;
  Return r(line_number);
}

TEST(Return, matchGivenLineNumber) {
  const unsigned int line_number = 123;
  Return r(line_number);
  ASSERT_EQ(r.line(), line_number);
}
