#include "Variable.h"
#include <gtest/gtest.h>

TEST(Variable, createVariable) { Variable v("name", 0); }

TEST(Variable, defaultValueIsZero) {
  const Variable v("name", 0);
  ASSERT_EQ(v.value(), 0);
}

TEST(Variable, valueMatchesConstantArguement) {
  const int x1 = 4, x2 = -7;
  const Variable v1("v1", x1), v2("v2", x2);
  ASSERT_EQ(v1.value(), x1);
  ASSERT_EQ(v2.value(), x2);
}

TEST(Variable, defaultConstantValueIsZero) {
  const Variable v("name");
  ASSERT_EQ(v.value(), 0);
}

TEST(Variable, getVariableName) {
  const Variable v1("name"), v2("ID");
  ASSERT_EQ(v1.name(), "name");
  ASSERT_EQ(v2.name(), "ID");
}

TEST(Variable, blankNameStringNamedUnknown) {
  const Variable v("");
  ASSERT_EQ(v.name(), "UNKNOWN");
}

TEST(Variable, defaultVariableHasKnownState) {
  const Variable v;
  ASSERT_EQ(v.name(), "UNKNOWN");
  ASSERT_EQ(v.value(), 0);
  ASSERT_EQ(v.format(), "UNKNOWN");
}

TEST(Variable, copiesHaveSameNameAndValue) {
  const Variable v1("v1", 123);
  const Variable v2(v1);
  ASSERT_EQ(v2.name(), v1.name());
  ASSERT_EQ(v2.value(), v1.value());
  ASSERT_EQ(v2.format(), v1.format());
}

TEST(Variable, canAssignUsingInteger) {
  Variable v;
  v.assign(-3);
}

TEST(Variable, assignmentChangesValueOnly) {
  const std::string name = "NAME";
  const int val1 = 123, val2 = 456;
  Variable v(name, val1);
  ASSERT_EQ(v.name(), name);
  ASSERT_EQ(v.value(), val1);
  v.assign(val2);
  ASSERT_EQ(v.name(), name);
  ASSERT_EQ(v.value(), val2);
}
