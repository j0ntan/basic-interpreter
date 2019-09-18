#include "Division.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Division, canCreateDivisionOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  Division d1(num1, num2), d2(num3, num4), d3(num1, num4), d4(num3, num2);
}

TEST(Division, canCreateNestedDivision) {
  Constant num1, num2, num3;
  Division d1(num1, num2);
  Division d2(d1, num3);
}

TEST(Division, addIntegerValuesAndNested) {
  Constant x(200), y(2), z(-40), zz(-5);
  Division positives(x, y), positive_and_negative(x, z), negatives(z, zz);
  Division nested(positives, zz);
  ASSERT_EQ(positives.value(), 100);
  ASSERT_EQ(negatives.value(), 8);
  ASSERT_EQ(positive_and_negative.value(), -5);
  ASSERT_EQ(nested.value(), -20);
}

TEST(Division, formatValuesAndNested) {
  Constant x(123), y(-456);
  Division pos_and_pos(x, x), pos_and_neg(x, y), neg_and_pos(y, x),
      neg_and_neg(y, y);
  Division nested(y, pos_and_neg);
  ASSERT_EQ(pos_and_pos.format(), "(123 / 123)");
  ASSERT_EQ(pos_and_neg.format(), "(123 / -456)");
  ASSERT_EQ(neg_and_pos.format(), "(-456 / 123)");
  ASSERT_EQ(neg_and_neg.format(), "(-456 / -456)");
  ASSERT_EQ(nested.format(), "(-456 / (123 / -456))");
}
