#include "AssignVariable.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(AssignVariable, createAssignVariable) {
  const unsigned int line_num = 1;
  const Constant zero, value(123);
  const Variable variable("NAME", zero);
  AssignVariable a(line_num, variable, value);
}

TEST(AssignVariable, matchGivenLineNumber) {
  const unsigned int line_num = 781;
  const Constant zero, value(123);
  const Variable variable("NAME", zero);
  AssignVariable a(line_num, variable, value);
  ASSERT_EQ(a.line(), 781);
}
