#include "Parser.h"
#include <gtest/gtest.h>

TEST(findNextExpression, callGetNextExpression) { findNextExpression("123"); }

TEST(findNextExpression, findSimplePositiiveInteger) {
  ASSERT_EQ(findNextExpression("123"), "123");
}
