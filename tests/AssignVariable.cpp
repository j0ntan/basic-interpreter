#include "AssignVariable.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(AssignVariable, createAssignVariable) {
  const unsigned int line_num = 1;
  const Constant zero, value(123);
  const Variable variable("NAME", zero);
  AssignVariable a(line_num, variable, value);
}
