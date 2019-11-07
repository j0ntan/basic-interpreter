#include "FormatStringSpacing.hpp"
#include <gtest/gtest.h>

TEST(FormatStringSpacing, canCallFormatFunction) { fix_spacing("test"); }

TEST(FormatStringSpacing, getStringFromFormatFunction) {
  std::string formatted = fix_spacing("test");
}

TEST(FormatStringSpacing, preFormattedStringHasNoChange) {
  ASSERT_EQ("test", fix_spacing("test"));
}

TEST(FormatStringSpacing, removeBeginningWhitespace) {
  ASSERT_EQ("test", fix_spacing(" test"));
  ASSERT_EQ("test", fix_spacing("\ttest"));
}

TEST(FormatStringSpacing, removeEndingWhitespace) {
  ASSERT_EQ("test", fix_spacing("test "));
  ASSERT_EQ("test", fix_spacing("test\t"));
}

TEST(FormatStringSpacing, removeExtraWhitespaceInBetweenWords) {
  ASSERT_EQ("two words", fix_spacing("two   words"));
}
