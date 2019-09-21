#include "ParserHelper.h"
#include <gtest/gtest.h>

TEST(IsNumericExpression, randomCharsNotExpression) {
  ASSERT_FALSE(isNumericExpression("a123sc.,)9*&585s"));
}

TEST(IsInteger, randomCharsNotInteger) {
  ASSERT_FALSE(isInteger("a123sc.,)9*&585s"));
}

TEST(IsInteger, positiveNumberIsInteger) { ASSERT_TRUE(isInteger("123456")); }

TEST(IsInteger, negativeNumberIsInteger) { ASSERT_TRUE(isInteger("-123456")); }

TEST(IsInteger, misplacedNegativeNotInteger) {
  ASSERT_FALSE(isInteger("12-3456"));
}

TEST(IsNumericExpression, positiveAndNegativeNumbersAreExpressions) {
  ASSERT_TRUE(isNumericExpression("123"));
  ASSERT_TRUE(isNumericExpression("-456"));
}

TEST(IsNumericExpression, leadingWhitespaceIntegerAllowed) {
  ASSERT_TRUE(isNumericExpression(" 123"));         // single space
  ASSERT_TRUE(isNumericExpression("\t123"));        // single tab
  ASSERT_TRUE(isNumericExpression(" \t  \t\t123")); // multiple space & tab
}

TEST(IsNumericExpression, trailingWhitespaceIntegerAllowed) {
  ASSERT_TRUE(isNumericExpression("123 "));         // single space
  ASSERT_TRUE(isNumericExpression("123\t"));        // single tab
  ASSERT_TRUE(isNumericExpression("123 \t  \t\t")); // multiple space & tab
}

TEST(IsNumericExpression, inBetweenWhitespaceIntegerNotAllowed) {
  ASSERT_FALSE(isNumericExpression("  12  3"));
  ASSERT_FALSE(isNumericExpression("12  3 \t"));
  ASSERT_FALSE(isNumericExpression("  12  3 \t"));
  ASSERT_FALSE(isNumericExpression("- 123"));
}

TEST(IsNumericExpression, noDigitStringNotExpression) {
  ASSERT_FALSE(isNumericExpression(" "));
  ASSERT_FALSE(isNumericExpression("\t"));
  ASSERT_FALSE(isNumericExpression("  \t "));
  ASSERT_FALSE(isNumericExpression("-"));
}

TEST(IsVariable, integerIsNotAVariable) {
  ASSERT_FALSE(isVariable("123"));
  ASSERT_FALSE(isVariable("-123"));
}

TEST(IsVariable, onlyUppercaseLettersAllowed) {
  ASSERT_TRUE(isVariable("VAR"));
  ASSERT_FALSE(isVariable("var"));
  ASSERT_FALSE(isVariable("VAR123"));
}

TEST(IsVariable, lengthMaximumIs8) {
  ASSERT_TRUE(isVariable("SHORT"));
  ASSERT_TRUE(isVariable("GOODNAME"));
  ASSERT_FALSE(isVariable("NAMETOOLONG"));
}

TEST(IsVariable, commandNameNotAllowed) {
  ASSERT_FALSE(isVariable("PRINT"));
  ASSERT_FALSE(isVariable("LET"));
  ASSERT_FALSE(isVariable("GOTO"));
  ASSERT_FALSE(isVariable("IF"));
  ASSERT_FALSE(isVariable("THEN"));
  ASSERT_FALSE(isVariable("GOSUB"));
  ASSERT_FALSE(isVariable("RETURN"));
  ASSERT_FALSE(isVariable("END"));
}

TEST(IsNumericExpression, variableIsExpression) {
  ASSERT_TRUE(isNumericExpression("VARIABLE"));
}

TEST(IsNumericExpression, leadingWhitespaceVariableAllowed) {
  ASSERT_TRUE(isNumericExpression(" VAR"));         // single space
  ASSERT_TRUE(isNumericExpression("\tVAR"));        // single tab
  ASSERT_TRUE(isNumericExpression(" \t  \t\tVAR")); // multiple space & tab
}

TEST(IsNumericExpression, trailingWhitespaceVariableAllowed) {
  ASSERT_TRUE(isNumericExpression("VAR "));         // single space
  ASSERT_TRUE(isNumericExpression("VAR\t"));        // single tab
  ASSERT_TRUE(isNumericExpression("VAR \t  \t\t")); // multiple space & tab
}

TEST(IsNumericExpression, inBetweenWhitespaceVariableNotAllowed) {
  ASSERT_FALSE(isNumericExpression("  VA  R"));
  ASSERT_FALSE(isNumericExpression("VA  R \t"));
  ASSERT_FALSE(isNumericExpression("  VA  R \t"));
}

TEST(IsArray, simpleArray) { ASSERT_TRUE(isArray("VAR[0]")); }

TEST(IsArray, arrayMustContainBrackets) {
  ASSERT_FALSE(isArray("VARIABLE"));
  ASSERT_FALSE(isArray("123"));
}

TEST(IsArray, bracketPairMustBeOrdered) { ASSERT_FALSE(isArray("VAR]0[")); }

TEST(IsArray, bracketMustNotBeEmpty) { ASSERT_FALSE(isArray("VAR[]")); }

TEST(IsArray, arrayNameMustComeFirst) { ASSERT_FALSE(isArray("[0]VAR")); }

TEST(IsArray, nameMustBeVariableName) {
  ASSERT_FALSE(isArray("var[0]"));
  ASSERT_FALSE(isArray("123[0]"));
  ASSERT_FALSE(isArray("VA R[0]"));
}

TEST(IsArray, whitespaceAfterNameAllowed) {
  ASSERT_TRUE(isArray("VAR [0]"));
  ASSERT_TRUE(isArray("VAR\t[0]"));
}

TEST(IsArray, indexCannotBeNegative) { ASSERT_FALSE(isArray("VAR[-1]")); }

TEST(IsArray, indexCanBeVariable) { ASSERT_TRUE(isArray("VAR[OTHER]")); }

TEST(IsArray, indexCanBeAnotherArrayElement) {
  ASSERT_TRUE(isArray("VAR[OTHER[0]]"));
  ASSERT_TRUE(isArray("FIRST[SECOND[THIRD[4]]]"));
  ASSERT_FALSE(isArray("VAR[invalid[0]"));
}

TEST(IsNumericExpression, arrayElementIsAnExpression) {
  ASSERT_TRUE(isNumericExpression("VAR[0]"));
  ASSERT_TRUE(isNumericExpression("VAR[OTHER[3]]"));
}

TEST(IsNumericExpression, whitespaceAroundArrayElementAllowed) {
  ASSERT_TRUE(isNumericExpression(" VAR[0]"));
  ASSERT_TRUE(isNumericExpression("\tVAR[0]"));
  ASSERT_TRUE(isNumericExpression("  \t VAR[0]"));
  ASSERT_TRUE(isNumericExpression("VAR[0] "));
  ASSERT_TRUE(isNumericExpression("VAR[0]\t"));
  ASSERT_TRUE(isNumericExpression("VAR[0]  \t\t "));
  ASSERT_TRUE(isNumericExpression("\t\t VAR[0] \t"));
  ASSERT_TRUE(isNumericExpression("  VAR[  OTHER [0]  ] "));
}

TEST(IsNumericExpression, whitespaceAroundArrayIndexAllowed) {
  ASSERT_TRUE(isNumericExpression("VAR[0 ]"));
  ASSERT_TRUE(isNumericExpression("VAR[ 0]"));
  ASSERT_TRUE(isNumericExpression("VAR[ 0 ]"));
  ASSERT_TRUE(isNumericExpression("VAR[ OTHER[3] ]"));
  ASSERT_TRUE(isNumericExpression("VAR[ OTHER[  3] ]"));
  ASSERT_TRUE(isNumericExpression("VAR[ OTHER[3  ] ]"));
  ASSERT_FALSE(isNumericExpression("VAR[ -1 ]"));
  ASSERT_FALSE(isNumericExpression("VAR[ wrong ]"));
  ASSERT_FALSE(isNumericExpression("VAR[ wrong[0] ]"));
}

TEST(IsBinaryExpression, simpleBinaryExpression) {
  ASSERT_TRUE(isBinaryExpression("(1+1)"));
  ASSERT_TRUE(isBinaryExpression("(1-1)"));
  ASSERT_TRUE(isBinaryExpression("(1*1)"));
  ASSERT_TRUE(isBinaryExpression("(1/1)"));
}

TEST(IsBinaryExpression, mustHaveEnclosingParenthesis) {
  ASSERT_FALSE(isBinaryExpression("(1+1"));
  ASSERT_FALSE(isBinaryExpression("1+1)"));
  ASSERT_FALSE(isBinaryExpression("1+1"));
  ASSERT_FALSE(isBinaryExpression(")1+1("));
  ASSERT_FALSE(isBinaryExpression("()1+1"));
}
