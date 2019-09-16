#include "Constant.h"
#include <gtest/gtest.h>

TEST(Constant, createConstant) { Constant c; }

TEST(Constant, defaultValueIsZero) {
  Constant c;
  ASSERT_EQ(c.value(), 0);
}

TEST(Constant, valueMatchesIntegerArguement) {
  int x1 = 4, x2 = -7;
  Constant c1(x1), c2(x2);
  ASSERT_EQ(c1.value(), x1);
  ASSERT_EQ(c2.value(), x2);
}

TEST(Constant, formatIntegerValueToString) {
  int x1 = 123, x2 = -8471234;
  Constant c1(x1), c2(x2), c3;
  ASSERT_EQ(c1.format(), "123");
  ASSERT_EQ(c2.format(), "-8471234");
  ASSERT_EQ(c3.format(), "0");
}
