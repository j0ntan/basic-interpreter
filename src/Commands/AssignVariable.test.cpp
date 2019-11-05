#include "AssignVariable.hpp"
#include <Expressions/Numeric/Constant.hpp>
#include <Expressions/Numeric/Variable.hpp>
#include <gtest/gtest.h>

TEST(AssignVariable, createAssignVariable) {
  const unsigned int line_num = 1;
  const Constant *value = new Constant(123);
  const Variable *variable = new Variable("NAME", 0);
  const AssignVariable assignVariable(line_num, variable, value);
}

TEST(AssignVariable, matchGivenLineNumber) {
  const unsigned int line_num = 781;
  const Constant *value = new Constant(123);
  const Variable *variable = new Variable("NAME", 0);
  const AssignVariable assignVariable(line_num, variable, value);
  ASSERT_EQ(assignVariable.line(), 781);
}

TEST(AssignVariable, format) {
  const Constant *zero = new Constant;
  const Variable *variable = new Variable("NAME");
  const AssignVariable assignVariable(1, variable, zero);
  ASSERT_EQ(assignVariable.format(), "1 LET NAME 0");
}
