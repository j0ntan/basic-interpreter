#include "Subtraction.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Subtraction, canCreateSubtractionOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  Subtraction s1(num1, num2), s2(num3, num4), s3(num1, num4), s4(num3, num2);
}

TEST(Subtraction, canCreateNestedSubtraction) {
  Constant num1, num2, num3;
  Subtraction s1(num1, num2);
  Subtraction s2(s1, num3);
}

TEST(Subtraction, subtractIntegerValuesAndNested) {
  Constant x(1), y(2), z(-3), zz(-8);
  Subtraction positives(x, y), positive_and_negative(x, z), negatives(zz, z);
  Subtraction nested(positives, y);
  ASSERT_EQ(positives.value(), -1);
  ASSERT_EQ(negatives.value(), -5);
  ASSERT_EQ(positive_and_negative.value(), 4);
  ASSERT_EQ(nested.value(), -3);
}
