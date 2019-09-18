#include "Equals.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Equals, canCreateEqualsOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  Equals e1(num1, num2), e2(num3, num4), e3(num1, num4), e4(num3, num2);
}

TEST(Equals, evaluateSimpleAndNestedExpressions) {
  Constant x(123), y(-456);
  Addition a(x, x);
  Addition nested(a, x);
  Equals e1(x, y), e2(a, x), e3(nested, x), e4(x, x);
  ASSERT_FALSE(e1.value());
  ASSERT_FALSE(e2.value());
  ASSERT_FALSE(e3.value());
  ASSERT_TRUE(e4.value());
}
