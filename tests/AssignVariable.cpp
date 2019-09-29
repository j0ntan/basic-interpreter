#include "AssignVariable.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(AssignVariable, createAssignVariable) {
  const unsigned int line_num = 1;
  const Constant value(123);
  const Variable variable("NAME", 0);
  AssignVariable a(line_num, variable, value);
}

TEST(AssignVariable, matchGivenLineNumber) {
  const unsigned int line_num = 781;
  const Constant value(123);
  const Variable variable("NAME", 0);
  AssignVariable a(line_num, variable, value);
  ASSERT_EQ(a.line(), 781);
}

TEST(AssignVariable, format) {
  const Constant zero;
  const Variable variable("NAME");
  AssignVariable a(1, variable, zero);
  ASSERT_EQ(a.format(), "1 LET NAME 0");
}
