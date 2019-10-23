#include "LessThan.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(LessThan, canCreateLessThanOfConstantsAndVariables) {
  const LessThan lessThan1(new Constant, new Constant),
      lessThan2(new Variable, new Variable),
      lessThan3(new Constant, new Variable),
      lessThan4(new Variable, new Constant);
}

TEST(LessThan, evaluateSimpleAndNestedExpressions) {
  const int x = 123, y = -456, z = 456;
  const Addition *addition = new Addition(new Constant(x), new Constant(x));
  const Addition *nested = new Addition(
      new Addition(new Constant(x), new Constant(x)), new Constant(z));
  const LessThan lessThan1(new Constant(x), new Constant(y)),
      lessThan2(new Constant(x), new Constant(x)),
      lessThan3(new Constant(y), new Constant(x)),
      lessThan4(new Constant(x), new Constant(z)),
      lessThan5(nested, new Constant(z));
  ASSERT_FALSE(lessThan1.value());
  ASSERT_FALSE(lessThan2.value());
  ASSERT_TRUE(lessThan3.value());
  ASSERT_TRUE(lessThan4.value());
  ASSERT_FALSE(lessThan5.value());
}

TEST(LessThan, formatExpressions) {
  const int x = 123, y = -456;
  const Addition *pos_and_neg = new Addition(new Constant(x), new Constant(y));
  const Addition *nested = new Addition(
      new Constant(y), new Addition(new Constant(x), new Constant(y)));
  const LessThan lessThan1(new Constant(x), new Constant(x)),
      lessThan2(pos_and_neg, new Constant(x)),
      lessThan3(nested, new Constant(x));
  ASSERT_EQ(lessThan1.format(), "123 < 123");
  ASSERT_EQ(lessThan2.format(), "(123 + -456) < 123");
  ASSERT_EQ(lessThan3.format(), "(-456 + (123 + -456)) < 123");
}
