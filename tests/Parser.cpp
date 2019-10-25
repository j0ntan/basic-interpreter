#include "Parser.h"
#include "NumericExpression.h"
#include <gtest/gtest.h>
#include <memory>

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

TEST(identifyAssignArrayCommand, bracketPairFollowsVariable) {
  ASSERT_FALSE(is_assign_array_cmd("1 LET X 0 1"));
  ASSERT_FALSE(is_assign_array_cmd("1 LET X[0 1"));
  ASSERT_FALSE(is_assign_array_cmd("1 LET X0] 1"));
}

TEST(identifyAssignArrayCommand, indexMustNotBeEmpty) {
  ASSERT_FALSE(is_assign_array_cmd("1 LET X[] 1"));
}

TEST(identifyAssignArrayCommand, indexIsNumericExpression) {
  ASSERT_FALSE(is_assign_array_cmd("1 LET X[invalid] 1"));
}

TEST(identifyAssignArrayCommand, arrayElementCanBeIndex) {
  ASSERT_TRUE(is_assign_array_cmd("1 LET X[Y[0]] 1"));
}

TEST(identifyAssignArrayCommand, hasValueString) {
  ASSERT_FALSE(is_assign_array_cmd("1 LET X[0]"));
}

TEST(identifyAssignArrayCommand, valueIsNumericExpression) {
  ASSERT_FALSE(is_assign_array_cmd("1 LET X[0] invalid"));
}

TEST(identifyGotoCommand, callGoto) { is_goto_cmd("1 GOTO 2"); }

TEST(identifyGotoCommand, mustHaveGotoKeyword) {
  ASSERT_TRUE(is_goto_cmd("1 GOTO 2"));
}

TEST(identifyGotoCommand, gotoKeywordIsIsolated) {
  ASSERT_FALSE(is_goto_cmd("1 GOTOEAT 2"));
}

TEST(identifyGotoCommand, hasJline) { ASSERT_FALSE(is_goto_cmd("1 GOTO ")); }

TEST(identifyGotoCommand, jlineIsInteger) {
  ASSERT_FALSE(is_goto_cmd("1 GOTO invalid"));
}

TEST(identifyGotoCommand, jlineIsPositiveInteger) {
  ASSERT_FALSE(is_goto_cmd("1 GOTO -1"));
}

TEST(identifyIfThenCommand, callIfThen) { is_if_then_cmd("1 IF X < Y THEN 2"); }

TEST(identifyIfThenCommand, mustHaveKeywords) {
  ASSERT_TRUE(is_if_then_cmd("1 IF X < Y THEN 2"));
}

TEST(identifyIfThenCommand, keywordsAreIsolated) {
  ASSERT_FALSE(is_if_then_cmd("1 DIFF X < Y THENCE 2"));
}

TEST(identifyIfThenCommand, keywordsAreOrdered) {
  ASSERT_FALSE(is_if_then_cmd("1 THEN X < Y IF 2"));
}

TEST(identifyIfThenCommand, hasBooleanExpression) {
  ASSERT_FALSE(is_if_then_cmd("1 IF  THEN 2"));
}

TEST(identifyIfThenCommand, booleanExpressionIsValid) {
  ASSERT_FALSE(is_if_then_cmd("1 IF invalid = 0 THEN 2"));
}

TEST(identifyIfThenCommand, hasJline) {
  ASSERT_FALSE(is_if_then_cmd("1 IF X>Y THEN"));
}

TEST(identifyIfThenCommand, jlineIsInteger) {
  ASSERT_FALSE(is_if_then_cmd("1 IF X>Y THEN Z"));
}

TEST(identifyIfThenCommand, jlineIsNotNegative) {
  ASSERT_FALSE(is_if_then_cmd("1 IF X>Y THEN -2"));
}

TEST(identifyGosubCommand, callGosub) { is_gosub_cmd("1 GOSUB 2"); }

TEST(identifyGosubCommand, hasGosubKeyword) {
  ASSERT_TRUE(is_gosub_cmd("1 GOSUB 2"));
}

TEST(identifyGosubCommand, gosubKeywordIsIsolated) {
  ASSERT_FALSE(is_gosub_cmd("1 ALGOSUBJECT 2"));
}

TEST(identifyGosubCommand, hasJline) { ASSERT_FALSE(is_gosub_cmd("1 GOSUB ")); }

TEST(identifyGosubCommand, jlineIsInteger) {
  ASSERT_FALSE(is_gosub_cmd("1 GOSUB VAR"));
}

TEST(identifyGosubCommand, jlineIsNonNegative) {
  ASSERT_FALSE(is_gosub_cmd("1 GOSUB -2"));
}

TEST(identifyReturnCommand, callReturn) { is_return_cmd("1 RETURN"); }

TEST(identifyReturnCommand, hasReturnKeyword) {
  ASSERT_TRUE(is_return_cmd("1 RETURN"));
}

TEST(identifyReturnCommand, returnIsIsolatedAtEnd) {
  ASSERT_FALSE(is_return_cmd("1 NORETURN"));
  ASSERT_FALSE(is_return_cmd("1 RETURNNOW"));
  ASSERT_FALSE(is_return_cmd("1 RETURN NOW"));
}

TEST(identifyEndCommand, callEnd) { is_end_cmd("1 END"); }

TEST(identifyEndCommand, hasEndKeyword) {
  ASSERT_TRUE(is_return_cmd("1 RETURN"));
}

TEST(identifyEndCommand, endIsIsolatedAtEnd) {
  ASSERT_FALSE(is_return_cmd("1 NOEND"));
  ASSERT_FALSE(is_return_cmd("1 ENDNOW"));
  ASSERT_FALSE(is_return_cmd("1 END NOW"));
}

TEST(NumericExpressionGenerator, callNumericExpressionGenerator) {
  numericExpressionGenerator("0");
}

TEST(NumericExpressionGenerator, returnsPointerToNumericExpression) {
  NumericExpression *expression = numericExpressionGenerator("0");
}

TEST(NumericExpressionGenerator, generateConstantExpression) {
  std::unique_ptr<NumericExpression> expression(
      numericExpressionGenerator("123"));
  ASSERT_EQ(expression->value(), 123);
  ASSERT_EQ(expression->format(), "123");
}

TEST(NumericExpressionGenerator, generateVariableExpression) {
  std::unique_ptr<NumericExpression> expression(
      numericExpressionGenerator("X"));
  ASSERT_EQ(expression->value(), 0);
  ASSERT_EQ(expression->format(), "X");
}

TEST(NumericExpressionGenerator, generateAdditionExpression) {
  std::unique_ptr<NumericExpression> expression(
      numericExpressionGenerator("(1+2)"));
  ASSERT_EQ(expression->value(), 3);
  ASSERT_EQ(expression->format(), "(1 + 2)");
}

TEST(NumericExpressionGenerator, generateSubtractionExpression) {
  std::unique_ptr<NumericExpression> expression(
      numericExpressionGenerator("(1-2)"));
  ASSERT_EQ(expression->value(), -1);
  ASSERT_EQ(expression->format(), "(1 - 2)");
}

TEST(NumericExpressionGenerator, generateMultiplicationExpression) {
  std::unique_ptr<NumericExpression> expression(
      numericExpressionGenerator("(2*3)"));
  ASSERT_EQ(expression->value(), 6);
  ASSERT_EQ(expression->format(), "(2 * 3)");
}

TEST(NumericExpressionGenerator, generateDivisionExpression) {
  std::unique_ptr<NumericExpression> expression(
      numericExpressionGenerator("(75/3)"));
  ASSERT_EQ(expression->value(), 25);
  ASSERT_EQ(expression->format(), "(75 / 3)");
}

TEST(NumericExpressionGenerator, ignoreWhitespace) {
  std::unique_ptr<NumericExpression> constantExpression(
      numericExpressionGenerator(" 123   "));
  ASSERT_EQ(constantExpression->value(), 123);
  ASSERT_EQ(constantExpression->format(), "123");
  std::unique_ptr<NumericExpression> variableExpression(
      numericExpressionGenerator("   VARIABLE"));
  ASSERT_EQ(variableExpression->value(), 0);
  ASSERT_EQ(variableExpression->format(), "VARIABLE");
  std::unique_ptr<NumericExpression> additionExpression(
      numericExpressionGenerator("  (   1  +2     ) "));
  ASSERT_EQ(additionExpression->value(), 3);
  ASSERT_EQ(additionExpression->format(), "(1 + 2)");
}
