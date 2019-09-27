#include "AssignArray.h"
#include "Array.h"
#include "Constant.h"
#include <gtest/gtest.h>

TEST(AssignArray, createSimpleAssignArray) {
  const unsigned int line_num = 1;
  const Constant index(123), value(456);
  const Array array("NAME", index);
  AssignArray a(line_num, array, value);
}

TEST(AssignArray, matchGivenLineNumber) {
  const unsigned int line_num = 15;
  const Constant index(123), value(456);
  const Array array("NAME", index);
  AssignArray a(line_num, array, value);
  ASSERT_EQ(a.line(), line_num);
}
