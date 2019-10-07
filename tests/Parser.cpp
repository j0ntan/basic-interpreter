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

TEST(hasLineNumber, ignoreLeadingWhitespace) {
  ASSERT_TRUE(has_line_number(" \t 1"));
}

TEST(identifyPrintCommand, callIsPrint) { is_print_cmd("1 PRINT 1"); }

TEST(identifyPrintCommand, mustHavePrintKeyword) {
  ASSERT_TRUE(is_print_cmd("1 PRINT 1"));
}

TEST(identifyPrintCommand, printKeywordMustBeIsolated) {
  ASSERT_FALSE(is_print_cmd("1 PRINTER 1"));
}

TEST(identifyPrintCommand, mustHaveNumericalExpressionValue) {
  ASSERT_FALSE(is_print_cmd("1 PRINT invalid"));
}

TEST(identifyAssignVariableCommand, callIsAssignVariable) {
  is_assign_variable_cmd("1 LET X 1");
}

TEST(identifyAssignVariableCommand, mustHaveLetKeyword) {
  ASSERT_TRUE(is_assign_variable_cmd("1 LET X 1"));
}

TEST(identifyAssignVariableCommand, letKeywordMustBeIsolated) {
  ASSERT_FALSE(is_assign_variable_cmd("1 LETTER X 1"));
}

TEST(identifyAssignVariableCommand, mustHaveVariableAndValueStrings) {
  ASSERT_TRUE(is_assign_variable_cmd("1 LET X 1"));
}

TEST(identifyAssignVariableCommand, variableStringIsVariableExpression) {
  ASSERT_FALSE(is_assign_variable_cmd("1 LET x 1"));
}

TEST(identifyAssignVariableCommand, valueStringIsNumericExpression) {
  ASSERT_FALSE(is_assign_variable_cmd("1 LET X x"));
}

TEST(identifyAssignArrayCommand, callIsAssignArray) {
  is_assign_array_cmd("1 LET X[0] 1");
}

TEST(identifyAssignArrayCommand, mustHaveLetKeyword) {
  ASSERT_TRUE(is_assign_array_cmd("1 LET X[0] 1"));
}

TEST(identifyAssignArrayCommand, letKeywordMustBeIsolated) {
  ASSERT_FALSE(is_assign_array_cmd("1 LETTER X[0] 1"));
}

TEST(identifyAssignArrayCommand, variableFollowsLetKeyword) {
  ASSERT_FALSE(is_assign_array_cmd("1 LET invalid[0] 1"));
}
