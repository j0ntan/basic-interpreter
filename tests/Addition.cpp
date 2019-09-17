#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Addition, canCreateAdditionOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  Addition a1(num1, num2), a2(num3, num4), a3(num1, num4), a4(num3, num2);
}

TEST(Addition, canCreateNestedAddition) {
  Constant num1, num2, num3;
  Addition a1(num1, num2);
  Addition a2(a1, num3);
}
