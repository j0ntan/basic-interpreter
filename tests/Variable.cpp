#include "Variable.h"
#include <gtest/gtest.h>

TEST(Variable, createVariable) { Variable v("name", Constant()); }

TEST(Variable, defaultValueIsZero) {
  Variable v("name", Constant());
  ASSERT_EQ(v.value(), 0);
}
