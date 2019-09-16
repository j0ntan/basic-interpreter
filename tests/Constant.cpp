#include "Constant.h"
#include <gtest/gtest.h>

TEST(Constant, createConstant) { Constant c; }

TEST(Constant, defaultValueIsZero) {
  Constant c;
  ASSERT_EQ(c.value(), 0);
}
