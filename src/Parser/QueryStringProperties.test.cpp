#include "QueryStringProperties.hpp"
#include <gtest/gtest.h>

TEST(HasOnlyDigits, callFunction) { has_only_digits("123"); }

TEST(HasOnlyDigits, getBoolResult) { ASSERT_TRUE(has_only_digits("123")); }

TEST(HasOnlyDigits, detectNonDigit) { ASSERT_FALSE(has_only_digits("12A3")); }

TEST(HasOnlyUppercaseLetters, callFunction) {
  has_only_uppercase_letters("ABC");
}

TEST(HasOnlyUppercaseLetters, getBoolResult) {
  ASSERT_TRUE(has_only_uppercase_letters("ABC"));
}
