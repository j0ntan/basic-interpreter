#include "Equals.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Equals, canCreateEqualsOfConstantsAndVariables) {
  Equals equals1(new Constant, new Constant),
      equals2(new Variable, new Variable), equals3(new Constant, new Variable),
      equals4(new Variable, new Constant);
}

TEST(Equals, evaluateSimpleAndNestedExpressions) {
  const int x = 123, y = -456;
  const Addition *addition = new Addition(new Constant(x), new Constant(x));
  const Addition *nested = new Addition(
      new Addition(new Constant(x), new Constant(x)), new Constant(x));
  const Equals equals1(new Constant(x), new Constant(y)),
      equals2(addition, new Constant(x)), equals3(nested, new Constant(x)),
      equals4(new Constant(x), new Constant(x));
  ASSERT_FALSE(equals1.value());
  ASSERT_FALSE(equals2.value());
  ASSERT_FALSE(equals3.value());
  ASSERT_TRUE(equals4.value());
}

TEST(Equals, formatExpressions) {
  const int x = 123, y = -456;
  const Addition *pos_and_neg = new Addition(new Constant(x), new Constant(y));
  const Addition *nested = new Addition(
      new Constant(y), new Addition(new Constant(x), new Constant(y)));
  const Equals equals1(new Constant(x), new Constant(x)),
      equals2(pos_and_neg, new Constant(x)), equals3(nested, new Constant(x));
  ASSERT_EQ(equals1.format(), "123 = 123");
  ASSERT_EQ(equals2.format(), "(123 + -456) = 123");
  ASSERT_EQ(equals3.format(), "(-456 + (123 + -456)) = 123");
}
