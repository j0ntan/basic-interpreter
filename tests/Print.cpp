#include "Print.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Print, canCreatePrint) {
  Constant c;
  Variable v;
  Addition a(v, c);
  Print p_const(1, c), p_var(1, v), p_addition(1, a);
}

TEST(Print, matchGivenLineNumber) {
  Constant zero, one(1);
  Print p(123, zero);
  ASSERT_EQ(p.line(), 123);
}

TEST(Print, format) {
  Constant c;
  Variable v;
  Addition a(v, c);
  Print p_const(1, c), p_var(1, v), p_addition(1, a);
  ASSERT_EQ(p_const.format(), "1 PRINT 0");
  ASSERT_EQ(p_var.format(), "1 PRINT UNKNOWN");
  ASSERT_EQ(p_addition.format(), "1 PRINT (UNKNOWN + 0)");
}
