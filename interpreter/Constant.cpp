#include "Constant.h"

Constant::Constant(int n) : val{n} {}

int Constant::value() const { return val; }

std::string Constant::format() const { return std::to_string(val); }
