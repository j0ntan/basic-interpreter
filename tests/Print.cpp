#include "Print.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Print, canCreatePrint) {
  const Constant c;
  const Variable v;
  const Addition a(v, c);
  const Print p_const(1, c), p_var(1, v), p_addition(1, a);
}

TEST(Print, matchGivenLineNumber) {
  const Constant zero, one(1);
  const Print p(123, zero);
  ASSERT_EQ(p.line(), 123);
}

TEST(Print, format) {
  const Constant c;
  const Variable v;
  const Addition a(v, c);
  const Print p_const(1, c), p_var(1, v), p_addition(1, a);
  ASSERT_EQ(p_const.format(), "1 PRINT 0");
  ASSERT_EQ(p_var.format(), "1 PRINT UNKNOWN");
  ASSERT_EQ(p_addition.format(), "1 PRINT (UNKNOWN + 0)");
}
