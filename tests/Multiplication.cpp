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
