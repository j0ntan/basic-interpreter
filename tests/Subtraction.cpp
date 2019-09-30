#include "Subtraction.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Subtraction, canCreateSubtractionOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  Subtraction subtraction1(num1, num2), subtraction2(num3, num4),
      subtraction3(num1, num4), subtraction4(num3, num2);
}

TEST(Subtraction, canCreateNestedSubtraction) {
  Constant num1, num2, num3;
  Subtraction subtraction1(num1, num2);
  Subtraction subtraction2(subtraction1, num3);
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

TEST(Subtraction, formatValuesAndNested) {
  Constant x(123), y(-456);
  Subtraction pos_and_pos(x, x), pos_and_neg(x, y), neg_and_pos(y, x),
      neg_and_neg(y, y);
  Subtraction nested(y, pos_and_neg);
  ASSERT_EQ(pos_and_pos.format(), "(123 - 123)");
  ASSERT_EQ(pos_and_neg.format(), "(123 - -456)");
  ASSERT_EQ(neg_and_pos.format(), "(-456 - 123)");
  ASSERT_EQ(neg_and_neg.format(), "(-456 - -456)");
  ASSERT_EQ(nested.format(), "(-456 - (123 - -456))");
}
