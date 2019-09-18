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
