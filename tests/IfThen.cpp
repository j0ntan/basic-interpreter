#include "IfThen.h"
#include "Constant.h"
#include "LessThan.h"
#include <gtest/gtest.h>

TEST(IfThen, createSimpleIfThen) {
  const unsigned int line_number = 123, jline = 456;
  const Constant num1(5), num2(8);
  const LessThan comparison(num1, num2);
  IfThen i(line_number, comparison, jline);
}

TEST(IfThen, matchGivenLineNumber) {
  const unsigned int line_number = 123, jline = 456;
  const Constant num1(5), num2(8);
  const LessThan comparison(num1, num2);
  IfThen i(line_number, comparison, jline);
  ASSERT_EQ(i.line(), line_number);
}
