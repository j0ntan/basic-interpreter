#include "Division.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Division, canCreateDivisionOfConstantsAndVariables) {
  const Constant num1, num2;
  const Variable num3, num4;
  const Division d1(num1, num2), d2(num3, num4), d3(num1, num4), d4(num3, num2);
}

TEST(Division, canCreateNestedDivision) {
  const Constant num1, num2, num3;
  const Division d1(num1, num2);
  const Division d2(d1, num3);
}

TEST(Division, addIntegerValuesAndNested) {
  const Constant x(200), y(2), z(-40), zz(-5);
  const Division positives(x, y), positive_and_negative(x, z), negatives(z, zz);
  const Division nested(positives, zz);
  ASSERT_EQ(positives.value(), 100);
  ASSERT_EQ(negatives.value(), 8);
  ASSERT_EQ(positive_and_negative.value(), -5);
  ASSERT_EQ(nested.value(), -20);
}

TEST(Division, formatValuesAndNested) {
  const Constant x(123), y(-456);
  const Division pos_and_pos(x, x), pos_and_neg(x, y), neg_and_pos(y, x),
      neg_and_neg(y, y);
  const Division nested(y, pos_and_neg);
  ASSERT_EQ(pos_and_pos.format(), "(123 / 123)");
  ASSERT_EQ(pos_and_neg.format(), "(123 / -456)");
  ASSERT_EQ(neg_and_pos.format(), "(-456 / 123)");
  ASSERT_EQ(neg_and_neg.format(), "(-456 / -456)");
  ASSERT_EQ(nested.format(), "(-456 / (123 / -456))");
}
