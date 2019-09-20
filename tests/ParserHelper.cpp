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
