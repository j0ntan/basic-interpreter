#include "QueryStringProperties.hpp"
#include <gtest/gtest.h>

TEST(HasOnlyDigits, callFunction) { has_only_digits("123"); }

TEST(HasOnlyDigits, getBoolResult) { ASSERT_TRUE(has_only_digits("123")); }
