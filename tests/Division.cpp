#include "Division.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Division, canCreateDivisionOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  Division d1(num1, num2), d2(num3, num4), d3(num1, num4), d4(num3, num2);
}

TEST(Division, canCreateNestedDivision) {
  Constant num1, num2, num3;
  Division d1(num1, num2);
  Division d2(d1, num3);
}
