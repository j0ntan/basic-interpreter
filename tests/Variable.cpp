#include "Variable.h"
#include <gtest/gtest.h>

TEST(Variable, createVariable) { Variable v("name", Constant()); }

TEST(Variable, defaultValueIsZero) {
  Variable v("name", Constant());
  ASSERT_EQ(v.value(), 0);
}

TEST(Variable, valueMatchesConstantArguement) {
  int x1 = 4, x2 = -7;
  Variable v1("v1", Constant(x1)), v2("v2", Constant(x2)) ;
  ASSERT_EQ(v1.value(), x1);
  ASSERT_EQ(v2.value(), x2);
}

TEST(Variable, defaultConstantValueIsZero) {
  Variable v("name");
  ASSERT_EQ(v.value(), 0);
}
