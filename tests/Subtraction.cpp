#include "Subtraction.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Subtraction, canCreateSubtractionOfConstantsAndVariables) {
  Subtraction subtraction1(new Constant, new Constant),
      subtraction2(new Variable, new Variable),
      subtraction3(new Constant, new Variable),
      subtraction4(new Variable, new Constant);
}

TEST(Subtraction, canCreateNestedSubtraction) {
  Subtraction *subtraction1 = new Subtraction(new Constant, new Constant);
  Subtraction subtraction2(subtraction1, new Constant);
}

TEST(Subtraction, subtractIntegerValuesAndNested) {
  const int x = 1, y = 2, z = -3, zz = -8;
  Subtraction *positives = new Subtraction(new Constant(x), new Constant(y)),
              positive_and_negative(new Constant(x), new Constant(z)),
              negatives(new Constant(zz), new Constant(z));
  Subtraction nested(positives, new Constant(y));
  ASSERT_EQ(positives->value(), -1);
  ASSERT_EQ(negatives.value(), -5);
  ASSERT_EQ(positive_and_negative.value(), 4);
  ASSERT_EQ(nested.value(), -3);
}

TEST(Subtraction, formatValuesAndNested) {
  const int x = 123, y = -456;
  Subtraction pos_and_pos(new Constant(x), new Constant(x)),
      *pos_and_neg = new Subtraction(new Constant(x), new Constant(y)),
      neg_and_pos(new Constant(y), new Constant(x)),
      neg_and_neg(new Constant(y), new Constant(y));
  Subtraction nested(new Constant(y), pos_and_neg);
  ASSERT_EQ(pos_and_pos.format(), "(123 - 123)");
  ASSERT_EQ(pos_and_neg->format(), "(123 - -456)");
  ASSERT_EQ(neg_and_pos.format(), "(-456 - 123)");
  ASSERT_EQ(neg_and_neg.format(), "(-456 - -456)");
  ASSERT_EQ(nested.format(), "(-456 - (123 - -456))");
}
