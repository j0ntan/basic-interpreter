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

TEST(Array, nameMatchesGivenName) {
  const Array a1("FIRST", Constant());
  const Array a2("SECOND", Constant());
  ASSERT_EQ(a1.name(), "FIRST");
  ASSERT_EQ(a2.name(), "SECOND");
}
