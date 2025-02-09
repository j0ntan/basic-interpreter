#include "IfThen.h"
#include "Constant.h"
#include "LessThan.h"
#include <gtest/gtest.h>

TEST(IfThen, createSimpleIfThen) {
  const unsigned int line_number = 123, jline = 456;
  const Constant *num1 = new Constant(5), *num2 = new Constant(8);
  const LessThan *comparison = new LessThan(num1, num2);
  const IfThen ifthen(line_number, comparison, jline);
}

TEST(IfThen, matchGivenLineNumber) {
  const unsigned int line_number = 123, jline = 456;
  const Constant *num1 = new Constant(5), *num2 = new Constant(8);
  const LessThan *comparison = new LessThan(num1, num2);
  const IfThen ifthen(line_number, comparison, jline);
  ASSERT_EQ(ifthen.line(), line_number);
}

TEST(IfThen, format) {
  const unsigned int line_number = 5, jline = 26;
  const Constant *num1 = new Constant(5), *num2 = new Constant(8);
  const LessThan *comparison = new LessThan(num1, num2);
  const IfThen ifthen(line_number, comparison, jline);
  ASSERT_EQ(ifthen.format(), "5 IF [5 < 8] THEN <26>");
}
