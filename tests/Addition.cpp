#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Addition, canCreateAdditionOfConstantsAndVariables) {
  const Addition a1(new Constant, new Constant), a2(new Variable, new Variable),
      a3(new Constant, new Variable), a4(new Variable, new Constant);
}

TEST(Addition, canCreateNestedAddition) {
  const Addition *inner = new const Addition(new Constant, new Constant);
  const Addition nested(inner, new Constant);
}

TEST(Addition, addIntegerValuesAndNested) {
  const int x = 1, y = 2, z = -3;
  const Addition *positives = new Addition(new Constant(x), new Constant(y)),
                 positive_and_negative(new Constant(x), new Constant(z)),
                 negatives(new Constant(z), new Constant(z));
  const Addition nested(positives, new Constant(y));
  ASSERT_EQ(positives->value(), 3);
  ASSERT_EQ(negatives.value(), -6);
  ASSERT_EQ(positive_and_negative.value(), -2);
  ASSERT_EQ(nested.value(), 5);
}

TEST(Addition, formatValuesAndNested) {

  const int x = 123, y = -456;
  const Addition pos_and_pos(new Constant(x), new Constant(x)),
      *pos_and_neg = new Addition(new Constant(x), new Constant(y)),
      neg_and_pos(new Constant(y), new Constant(x)),
      neg_and_neg(new Constant(y), new Constant(y));
  const Addition nested(new Constant(y), pos_and_neg);
  ASSERT_EQ(pos_and_pos.format(), "(123 + 123)");
  ASSERT_EQ(pos_and_neg->format(), "(123 + -456)");
  ASSERT_EQ(neg_and_pos.format(), "(-456 + 123)");
  ASSERT_EQ(neg_and_neg.format(), "(-456 + -456)");
  ASSERT_EQ(nested.format(), "(-456 + (123 + -456))");
}
