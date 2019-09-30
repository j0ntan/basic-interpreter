#include "Equals.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Equals, canCreateEqualsOfConstantsAndVariables) {
  const Constant num1, num2;
  const Variable num3, num4;
  Equals equals1(num1, num2), equals2(num3, num4), equals3(num1, num4),
      equals4(num3, num2);
}

TEST(Equals, evaluateSimpleAndNestedExpressions) {
  const Constant x(123), y(-456);
  const Addition addition(x, x);
  const Addition nested(addition, x);
  const Equals equals1(x, y), equals2(addition, x), equals3(nested, x),
      equals4(x, x);
  ASSERT_FALSE(equals1.value());
  ASSERT_FALSE(equals2.value());
  ASSERT_FALSE(equals3.value());
  ASSERT_TRUE(equals4.value());
}

TEST(Equals, formatExpressions) {
  const Constant x(123), y(-456);
  const Addition pos_and_neg(x, y);
  const Addition nested(y, pos_and_neg);
  const Equals equals1(x, x), equals2(pos_and_neg, x), equals3(nested, x);
  ASSERT_EQ(equals1.format(), "123 = 123");
  ASSERT_EQ(equals2.format(), "(123 + -456) = 123");
  ASSERT_EQ(equals3.format(), "(-456 + (123 + -456)) = 123");
}
