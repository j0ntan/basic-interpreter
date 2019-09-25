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
