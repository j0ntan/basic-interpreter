#include "Multiplication.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Multiplication, canCreateMultiplicationOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  Multiplication m1(num1, num2), m2(num3, num4), m3(num1, num4), m4(num3, num2);
}

TEST(Multiplication, canCreateNestedMultiplication) {
  Constant num1, num2, num3;
  Multiplication m1(num1, num2);
  Multiplication m2(m1, num3);
}
