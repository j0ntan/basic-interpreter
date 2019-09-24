#include "Array.h"

Array::Array(std::string name, const NumericExpression &index)
    : array_name{std::move(name)} {}

int Array::value() const { return 0; }

std::string Array::format() const { return std::string(); }

std::string Array::name() const { return array_name; }
