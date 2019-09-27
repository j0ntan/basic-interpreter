#include "End.h"
#include <gtest/gtest.h>

TEST(End, createSimpleEnd) {
  const unsigned int line_number = 123;
  End e(line_number);
}
