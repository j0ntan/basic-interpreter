#include "Array.h"
#include "Constant.h"
#include <gtest/gtest.h>

TEST(Array, createArray) {
  Constant index;
  Array a("NAME", index);
}
