#include "AssignArray.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(AssignArray, createSimpleAssignArray) {
  const unsigned int line_num = 1;
  const Constant index(123), value(456);
  const Variable name;
  AssignArray a(line_num, name, index, value);
}

TEST(AssignArray, matchGivenLineNumber) {
  const unsigned int line_num = 15;
  const Constant index(123), value(456);
  const Variable name;
  AssignArray a(line_num, name, index, value);
  ASSERT_EQ(a.line(), line_num);
}

TEST(AssignArray, format) {
  const unsigned int line_num = 1;
  const Constant index(123), value(456);
  const Variable name("NAME");
  AssignArray a(line_num, name, index, value);
  ASSERT_EQ(a.format(), "1 LET NAME[123] 456");
}
