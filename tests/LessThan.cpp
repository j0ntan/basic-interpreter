#include "LessThan.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(LessThan, canCreateLessThanOfConstantsAndVariables) {
  const Constant num1, num2;
  const Variable num3, num4;
  const LessThan l1(num1, num2), l2(num3, num4), l3(num1, num4), l4(num3, num2);
}

TEST(LessThan, evaluateSimpleAndNestedExpressions) {
  const Constant x(123), y(-456), z(456);
  const Addition a(x, x);
  const Addition nested(a, z);
  const LessThan l1(x, y), l2(x, x), l3(y, x), l4(x, z), l5(nested, z);
  ASSERT_FALSE(l1.value());
  ASSERT_FALSE(l2.value());
  ASSERT_TRUE(l3.value());
  ASSERT_TRUE(l4.value());
  ASSERT_FALSE(l5.value());
}

TEST(LessThan, formatExpressions) {
  const Constant x(123), y(-456);
  const Addition pos_and_neg(x, y);
  const Addition nested(y, pos_and_neg);
  const LessThan l1(x, x), l2(pos_and_neg, x), l3(nested, x);
  ASSERT_EQ(l1.format(), "123 < 123");
  ASSERT_EQ(l2.format(), "(123 + -456) < 123");
  ASSERT_EQ(l3.format(), "(-456 + (123 + -456)) < 123");
}
