#include "Multiplication.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Multiplication, canCreateMultiplicationOfConstantsAndVariables) {
  const Multiplication multiplication1(new Constant, new Constant),
      multiplication2(new Variable, new Variable),
      multiplication3(new Constant, new Variable),
      multiplication4(new Variable, new Constant);
}

TEST(Multiplication, canCreateNestedMultiplication) {
  const Multiplication *multiplication1 =
      new Multiplication(new Constant, new Constant);
  const Multiplication multiplication2(multiplication1, new Constant);
}

TEST(Multiplication, multiplyIntegerValuesAndNested) {
  const int x = 5, y = 2, z = -3;
  const Multiplication *positives =
                           new Multiplication(new Constant(x), new Constant(y)),
                       positive_and_negative(new Constant(x), new Constant(z)),
                       negatives(new Constant(z), new Constant(z));
  const Multiplication nested(positives, new Constant(y));
  ASSERT_EQ(positives->value(), 10);
  ASSERT_EQ(negatives.value(), 9);
  ASSERT_EQ(positive_and_negative.value(), -15);
  ASSERT_EQ(nested.value(), 20);
}

TEST(Multiplication, formatValuesAndNested) {
  const int x = 123, y = -456;
  const Multiplication pos_and_pos(new Constant(x), new Constant(x)),
      *pos_and_neg = new Multiplication(new Constant(x), new Constant(y)),
      neg_and_pos(new Constant(y), new Constant(x)),
      neg_and_neg(new Constant(y), new Constant(y));
  const Multiplication nested(new Constant(y), pos_and_neg);
  ASSERT_EQ(pos_and_pos.format(), "(123 * 123)");
  ASSERT_EQ(pos_and_neg->format(), "(123 * -456)");
  ASSERT_EQ(neg_and_pos.format(), "(-456 * 123)");
  ASSERT_EQ(neg_and_neg.format(), "(-456 * -456)");
  ASSERT_EQ(nested.format(), "(-456 * (123 * -456))");
}
