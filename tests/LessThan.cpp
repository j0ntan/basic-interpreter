#include "LessThan.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(LessThan, canCreateLessThanOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  LessThan l1(num1, num2), l2(num3, num4), l3(num1, num4), l4(num3, num2);
}
