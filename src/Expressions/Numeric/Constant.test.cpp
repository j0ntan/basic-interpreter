#include "Constant.hpp"
#include <gtest/gtest.h>

TEST(Constant, createConstant) { const Constant c; }

TEST(Constant, defaultValueIsZero) {
  const Constant constant;
  ASSERT_EQ(constant.value(), 0);
}

TEST(Constant, valueMatchesIntegerArguement) {
  const int x1 = 4, x2 = -7;
  const Constant constant1(x1), constant2(x2);
  ASSERT_EQ(constant1.value(), x1);
  ASSERT_EQ(constant2.value(), x2);
}

TEST(Constant, formatIntegerValueToString) {
  const int x1 = 123, x2 = -8471234;
  const Constant constant1(x1), constant2(x2), constant3;
  ASSERT_EQ(constant1.format(), "123");
  ASSERT_EQ(constant2.format(), "-8471234");
  ASSERT_EQ(constant3.format(), "0");
}
