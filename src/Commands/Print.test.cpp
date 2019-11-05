#include "Print.hpp"
#include <Expressions/Numeric/Addition.hpp>
#include <Expressions/Numeric/Constant.hpp>
#include <Expressions/Numeric/Variable.hpp>
#include <gtest/gtest.h>

TEST(Print, canCreatePrint) {
  const Addition *addition = new Addition(new Variable, new Constant);
  const Print print_const(1, new Constant), print_var(1, new Variable),
      print_addition(1, addition);
}

TEST(Print, matchGivenLineNumber) {
  const Print p(123, new Constant(0));
  ASSERT_EQ(p.line(), 123);
}

TEST(Print, format) {
  const Addition *addition = new Addition(new Variable, new Constant);
  const Print print_const(1, new Constant), print_var(1, new Variable),
      print_addition(1, addition);
  ASSERT_EQ(print_const.format(), "1 PRINT 0");
  ASSERT_EQ(print_var.format(), "1 PRINT UNKNOWN");
  ASSERT_EQ(print_addition.format(), "1 PRINT (UNKNOWN + 0)");
}
