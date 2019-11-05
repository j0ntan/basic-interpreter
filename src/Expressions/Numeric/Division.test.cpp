#include "Constant.hpp"
#include "Division.hpp"
#include "Variable.hpp"
#include <gtest/gtest.h>

TEST(Division, canCreateDivisionOfConstantsAndVariables) {
  const Division division1(new Constant, new Constant),
      division2(new Variable, new Variable),
      division3(new Constant, new Variable),
      division4(new Variable, new Constant);
}

TEST(Division, canCreateNestedDivision) {
  const Division *division1 = new Division(new Constant, new Constant);
  const Division division2(division1, new Constant);
}

TEST(Division, addIntegerValuesAndNested) {
  const int x = 200, y = 2, z = -40, zz = -5;
  const Division *positives = new Division(new Constant(x), new Constant(y)),
                 positive_and_negative(new Constant(x), new Constant(z)),
                 negatives(new Constant(z), new Constant(zz));
  const Division nested(positives, new Constant(zz));
  ASSERT_EQ(positives->value(), 100);
  ASSERT_EQ(negatives.value(), 8);
  ASSERT_EQ(positive_and_negative.value(), -5);
  ASSERT_EQ(nested.value(), -20);
}

TEST(Division, formatValuesAndNested) {
  const int x = 123, y = -456;
  const Division pos_and_pos(new Constant(x), new Constant(x)),
      *pos_and_neg = new Division(new Constant(x), new Constant(y)),
      neg_and_pos(new Constant(y), new Constant(x)),
      neg_and_neg(new Constant(y), new Constant(y));
  const Division nested(new Constant(y), pos_and_neg);
  ASSERT_EQ(pos_and_pos.format(), "(123 / 123)");
  ASSERT_EQ(pos_and_neg->format(), "(123 / -456)");
  ASSERT_EQ(neg_and_pos.format(), "(-456 / 123)");
  ASSERT_EQ(neg_and_neg.format(), "(-456 / -456)");
  ASSERT_EQ(nested.format(), "(-456 / (123 / -456))");
}
