#include "FormatStringSpacing.hpp"
#include <gtest/gtest.h>

TEST(FormatStringSpacing, canCallFormatFunction) { fix_spacing("test"); }

TEST(FormatStringSpacing, getStringFromFormatFunction) {
  std::string formatted = fix_spacing("test");
}
