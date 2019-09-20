#include "ParserHelper.h"
#include <gtest/gtest.h>

TEST(IsNumericExpression, randomCharsNotExpression) {
  ASSERT_FALSE(isNumericExpression("a123sc.,)9*&585s"));
}
