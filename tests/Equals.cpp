#include "Equals.h"
#include "Addition.h"
#include "Constant.h"
#include "Variable.h"
#include <gtest/gtest.h>

TEST(Equals, canCreateEqualsOfConstantsAndVariables) {
  Constant num1, num2;
  Variable num3, num4;
  Equals e1(num1, num2), e2(num3, num4), e3(num1, num4), e4(num3, num2);
}
