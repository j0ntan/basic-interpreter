#include "Variable.h"
#include <gtest/gtest.h>

TEST(Variable, createVariable) { Variable v("name", Constant()); }
