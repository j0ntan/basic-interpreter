#include "GoSub.h"
#include <gtest/gtest.h>

TEST(GoSub, createSimpleGoSub) {
  const unsigned int line_number = 123, jline = 456;
  GoSub g(line_number, jline);
}
