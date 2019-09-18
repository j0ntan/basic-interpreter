#include "Multiplication.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Multiplication, canCreateMultiplicationOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  Multiplication m1(num1, num2), m2(num3, num4), m3(num1, num4), m4(num3, num2);
}

TEST(Multiplication, canCreateNestedMultiplication) {
  Constant num1, num2, num3;
  Multiplication m1(num1, num2);
  Multiplication m2(m1, num3);
}

TEST(Multiplication, multiplyIntegerValuesAndNested) {
  Constant x(5), y(2), z(-3);
  Multiplication positives(x, y), positive_and_negative(x, z), negatives(z, z);
  Multiplication nested(positives, y);
  ASSERT_EQ(positives.value(), 10);
  ASSERT_EQ(negatives.value(), 9);
  ASSERT_EQ(positive_and_negative.value(), -15);
  ASSERT_EQ(nested.value(), 20);
}

TEST(Multiplication, formatValuesAndNested) {
  Constant x(123), y(-456);
  Multiplication pos_and_pos(x, x), pos_and_neg(x, y), neg_and_pos(y, x),
      neg_and_neg(y, y);
  Multiplication nested(y, pos_and_neg);
  ASSERT_EQ(pos_and_pos.format(), "(123 * 123)");
  ASSERT_EQ(pos_and_neg.format(), "(123 * -456)");
  ASSERT_EQ(neg_and_pos.format(), "(-456 * 123)");
  ASSERT_EQ(neg_and_neg.format(), "(-456 * -456)");
  ASSERT_EQ(nested.format(), "(-456 * (123 * -456))");
}
