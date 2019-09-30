#include "AssignVariable.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(AssignVariable, createAssignVariable) {
  const unsigned int line_num = 1;
  const Constant value(123);
  const Variable variable("NAME", 0);
  const AssignVariable assignVariable(line_num, variable, value);
}

TEST(AssignVariable, matchGivenLineNumber) {
  const unsigned int line_num = 781;
  const Constant value(123);
  const Variable variable("NAME", 0);
  const AssignVariable assignVariable(line_num, variable, value);
  ASSERT_EQ(assignVariable.line(), 781);
}

TEST(AssignVariable, format) {
  const Constant zero;
  const Variable variable("NAME");
  const AssignVariable assignVariable(1, variable, zero);
  ASSERT_EQ(assignVariable.format(), "1 LET NAME 0");
}
