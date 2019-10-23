#include "AssignArray.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(AssignArray, createSimpleAssignArray) {
  const unsigned int line_num = 1;
  const Constant *index = new Constant(123), *value = new Constant(456);
  const Variable *name = new Variable;
  const AssignArray assignArray(line_num, name, index, value);
}

TEST(AssignArray, matchGivenLineNumber) {
  const unsigned int line_num = 15;
  const Constant *index = new Constant(123), *value = new Constant(456);
  const Variable *name = new Variable;
  const AssignArray assignArray(line_num, name, index, value);
  ASSERT_EQ(assignArray.line(), line_num);
}

TEST(AssignArray, format) {
  const unsigned int line_num = 1;
  const Constant *index = new Constant(123), *value = new Constant(456);
  const Variable *name = new Variable("NAME");
  const AssignArray assignArray(line_num, name, index, value);
  ASSERT_EQ(assignArray.format(), "1 LET NAME[123] 456");
}
