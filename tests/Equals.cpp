#include "Equals.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Equals, canCreateEqualsOfConstantsAndVariables) {
  const Constant num1, num2;
  const Variable num3, num4;
  Equals e1(num1, num2), e2(num3, num4), e3(num1, num4), e4(num3, num2);
}

TEST(Equals, evaluateSimpleAndNestedExpressions) {
  const Constant x(123), y(-456);
  const Addition a(x, x);
  const Addition nested(a, x);
  const Equals e1(x, y), e2(a, x), e3(nested, x), e4(x, x);
  ASSERT_FALSE(e1.value());
  ASSERT_FALSE(e2.value());
  ASSERT_FALSE(e3.value());
  ASSERT_TRUE(e4.value());
}

TEST(Equals, formatExpressions) {
  const Constant x(123), y(-456);
  const Addition pos_and_neg(x, y);
  const Addition nested(y, pos_and_neg);
  const Equals l1(x, x), l2(pos_and_neg, x), l3(nested, x);
  ASSERT_EQ(l1.format(), "123 = 123");
  ASSERT_EQ(l2.format(), "(123 + -456) = 123");
  ASSERT_EQ(l3.format(), "(-456 + (123 + -456)) = 123");
}
