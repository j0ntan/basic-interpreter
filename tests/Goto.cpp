#include "Goto.h"
#include <gtest/gtest.h>

TEST(Goto, createSimpleGoto) {
  const unsigned int line_number = 123, jline = 456;
  Goto g(line_number, jline);
}
