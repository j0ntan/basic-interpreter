#include "Print.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Print, canCreatePrint) {
  const Constant constant;
  const Variable variable;
  const Addition addition(variable, constant);
  const Print print_const(1, constant), print_var(1, variable),
      print_addition(1, addition);
}

TEST(Print, matchGivenLineNumber) {
  const Constant zero, one(1);
  const Print p(123, zero);
  ASSERT_EQ(p.line(), 123);
}

TEST(Print, format) {
  const Constant constant;
  const Variable variable;
  const Addition addition(variable, constant);
  const Print print_const(1, constant), print_var(1, variable),
      print_addition(1, addition);
  ASSERT_EQ(print_const.format(), "1 PRINT 0");
  ASSERT_EQ(print_var.format(), "1 PRINT UNKNOWN");
  ASSERT_EQ(print_addition.format(), "1 PRINT (UNKNOWN + 0)");
}
