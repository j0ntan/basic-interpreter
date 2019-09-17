#include "Variable.h"
#include <gtest/gtest.h>

TEST(Variable, createVariable) { Variable v("name", Constant()); }

TEST(Variable, defaultValueIsZero) {
  Variable v("name", Constant());
  ASSERT_EQ(v.value(), 0);
}

TEST(Variable, valueMatchesConstantArguement) {
  int x1 = 4, x2 = -7;
  Variable v1("v1", Constant(x1)), v2("v2", Constant(x2));
  ASSERT_EQ(v1.value(), x1);
  ASSERT_EQ(v2.value(), x2);
}

TEST(Variable, defaultConstantValueIsZero) {
  Variable v("name");
  ASSERT_EQ(v.value(), 0);
}

TEST(Variable, formatIntegerValueToString) {
  int x1 = 123, x2 = -8471234;
  Variable v1("", Constant{x1}), v2("", Constant{x2}), v3("");
  ASSERT_EQ(v1.format(), "123");
  ASSERT_EQ(v2.format(), "-8471234");
  ASSERT_EQ(v3.format(), "0");
}

TEST(Variable, getVariableName) {
  Variable v1("name"), v2("ID");
  ASSERT_EQ(v1.name(), "name");
  ASSERT_EQ(v2.name(), "ID");
}

TEST(Variable, blankNameStringNamedUnknown) {
  Variable v("");
  ASSERT_EQ(v.name(), "unknown");
}

TEST(Variable, defaultVariableHasKnownState) {
  Variable v;
  ASSERT_EQ(v.name(), "unknown");
  ASSERT_EQ(v.value(), 0);
  ASSERT_EQ(v.format(), "0");
}
