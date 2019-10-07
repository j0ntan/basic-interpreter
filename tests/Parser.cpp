#include "Parser.h"
#include <gtest/gtest.h>

TEST(findNextExpression, callGetNextExpression) { findNextExpression("123"); }

TEST(findNextExpression, findSimplePositiiveInteger) {
  ASSERT_EQ(findNextExpression("123"), "123");
}

TEST(findNextExpression, findSimpleNegativeInteger) {
  ASSERT_EQ(findNextExpression("-123"), "-123");
}

TEST(findNextExpression, findVariable) {
  ASSERT_EQ(findNextExpression("VAR"), "VAR");
}

TEST(findNextExpression, findBinaryExpression) {
  ASSERT_EQ(findNextExpression("(1+1)"), "(1+1)");
  ASSERT_EQ(findNextExpression("(VAR+134)"), "(VAR+134)");
}

TEST(findNextExpression, findNestedBinaryExpression) {
  ASSERT_EQ(findNextExpression("((1+1)+1)"), "((1+1)+1)");
}

TEST(findNextExpression, findFirstOccurringBinaryExpression) {
  ASSERT_EQ(findNextExpression("(1+1) (1+1)"), "(1+1)");
}

TEST(findNextExpression, findExpressionWithLeadingWhitespace) {
  ASSERT_EQ(findNextExpression("    -123"), "-123");
  ASSERT_EQ(findNextExpression("  VAR"), "VAR");
  ASSERT_EQ(findNextExpression("   (1+1)"), "(1+1)");
}

TEST(hasLineNumber, callHasLineNumber) { has_line_number("1"); }

TEST(hasLineNumber, mustIncludeANumber) { ASSERT_TRUE(has_line_number("1")); }

TEST(hasLineNumber, mustBeginWithLineNumber) {
  ASSERT_TRUE(has_line_number("1 X"));
  ASSERT_FALSE(has_line_number("X 1"));
}
