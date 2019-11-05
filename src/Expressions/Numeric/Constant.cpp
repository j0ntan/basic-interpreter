#include "Constant.hpp"

Constant::Constant(int value) : integral_value{value} {}

int Constant::value() const { return integral_value; }

std::string Constant::format() const { return std::to_string(integral_value); }
