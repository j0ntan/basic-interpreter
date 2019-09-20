#include "ParserHelper.h"
#include <gtest/gtest.h>

TEST(IsNumericExpression, randomCharsNotExpression) {
  ASSERT_FALSE(isNumericExpression("a123sc.,)9*&585s"));
}

TEST(IsInteger, randomCharsNotInteger) {
  ASSERT_FALSE(isInteger("a123sc.,)9*&585s"));
}
