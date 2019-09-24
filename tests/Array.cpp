#include "Array.h"
#include "Constant.h"
#include <gtest/gtest.h>

TEST(Array, createArray) {
  Constant index;
  Array a("NAME", index);
}

TEST(Array, getArrayName) {
  const Array a("NAME", Constant());
  a.name();
}
