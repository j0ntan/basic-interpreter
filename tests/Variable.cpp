#include "Variable.h"
#include <gtest/gtest.h>

TEST(Variable, createVariable) { Variable variable("name", 0); }

TEST(Variable, defaultValueIsZero) {
  const Variable variable("name", 0);
  ASSERT_EQ(variable.value(), 0);
}

TEST(Variable, valueMatchesConstantArguement) {
  const int x1 = 4, x2 = -7;
  const Variable variable1("variable1", x1), variable2("variable2", x2);
  ASSERT_EQ(variable1.value(), x1);
  ASSERT_EQ(variable2.value(), x2);
}

TEST(Variable, defaultConstantValueIsZero) {
  const Variable variable("name");
  ASSERT_EQ(variable.value(), 0);
}

TEST(Variable, getVariableName) {
  const Variable variable1("name"), variable2("ID");
  ASSERT_EQ(variable1.name(), "name");
  ASSERT_EQ(variable2.name(), "ID");
}

TEST(Variable, blankNameStringNamedUnknown) {
  const Variable variable("");
  ASSERT_EQ(variable.name(), "UNKNOWN");
}

TEST(Variable, defaultVariableHasKnownState) {
  const Variable variable;
  ASSERT_EQ(variable.name(), "UNKNOWN");
  ASSERT_EQ(variable.value(), 0);
  ASSERT_EQ(variable.format(), "UNKNOWN");
}

TEST(Variable, copiesHaveSameNameAndValue) {
  const Variable variable1("variable1", 123);
  const Variable variable2(variable1);
  ASSERT_EQ(variable2.name(), variable1.name());
  ASSERT_EQ(variable2.value(), variable1.value());
  ASSERT_EQ(variable2.format(), variable1.format());
}

TEST(Variable, canAssignUsingInteger) {
  Variable variable;
  variable.assign(-3);
}

TEST(Variable, assignmentChangesValueOnly) {
  const std::string name = "NAME";
  const int val1 = 123, val2 = 456;
  Variable variable(name, val1);
  ASSERT_EQ(variable.name(), name);
  ASSERT_EQ(variable.value(), val1);
  variable.assign(val2);
  ASSERT_EQ(variable.name(), name);
  ASSERT_EQ(variable.value(), val2);
}
