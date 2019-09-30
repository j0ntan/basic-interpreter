#include "LessThan.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(LessThan, canCreateLessThanOfConstantsAndVariables) {
  const Constant num1, num2;
  const Variable num3, num4;
  const LessThan lessThan1(num1, num2), lessThan2(num3, num4),
      lessThan3(num1, num4), lessThan4(num3, num2);
}

TEST(LessThan, evaluateSimpleAndNestedExpressions) {
  const Constant x(123), y(-456), z(456);
  const Addition addition(x, x);
  const Addition nested(addition, z);
  const LessThan lessThan1(x, y), lessThan2(x, x), lessThan3(y, x),
      lessThan4(x, z), lessThan5(nested, z);
  ASSERT_FALSE(lessThan1.value());
  ASSERT_FALSE(lessThan2.value());
  ASSERT_TRUE(lessThan3.value());
  ASSERT_TRUE(lessThan4.value());
  ASSERT_FALSE(lessThan5.value());
}

TEST(LessThan, formatExpressions) {
  const Constant x(123), y(-456);
  const Addition pos_and_neg(x, y);
  const Addition nested(y, pos_and_neg);
  const LessThan lessThan1(x, x), lessThan2(pos_and_neg, x),
      lessThan3(nested, x);
  ASSERT_EQ(lessThan1.format(), "123 < 123");
  ASSERT_EQ(lessThan2.format(), "(123 + -456) < 123");
  ASSERT_EQ(lessThan3.format(), "(-456 + (123 + -456)) < 123");
}
