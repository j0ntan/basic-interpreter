#include "Return.h"
#include <gtest/gtest.h>

TEST(Return, createSimpleReturn) {
  const unsigned int line_number = 123;
  Return r(line_number);
}
