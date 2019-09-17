#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Addition, canCreateAdditionOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  Addition a1(num1, num2), a2(num3, num4), a3(num1, num4), a4(num3, num2);
}

TEST(Addition, canCreateNestedAddition) {
  Constant num1, num2, num3;
  Addition a1(num1, num2);
  Addition a2(a1, num3);
}

TEST(Addition, addIntegerValuesAndNested) {
  Constant x(1), y(2), z(-3);
  Addition positives(x, y), positive_and_negative(x, z), negatives(z, z);
  Addition nested(positives, y);
  ASSERT_EQ(positives.value(), 3);
  ASSERT_EQ(negatives.value(), -6);
  ASSERT_EQ(positive_and_negative.value(), -2);
  ASSERT_EQ(nested.value(), 5);
}

TEST(Addition, formatValuesAndNested) {
  Constant x(123), y(-456);
  Addition pos_and_pos(x, x), pos_and_neg(x, y), neg_and_pos(y, x),
      neg_and_neg(y, y);
  Addition nested(y, pos_and_neg);
  ASSERT_EQ(pos_and_pos.format(), "(123 + 123)");
  ASSERT_EQ(pos_and_neg.format(), "(123 + -456)");
  ASSERT_EQ(neg_and_pos.format(), "(-456 + 123)");
  ASSERT_EQ(neg_and_neg.format(), "(-456 + -456)");
  ASSERT_EQ(nested.format(), "(-456 + (123 + -456))");
}
