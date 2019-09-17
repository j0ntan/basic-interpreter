#include "Variable.h"
#include <utility>

Variable::Variable(std::string name, Constant value)
    : var_name{std::move(name)}, var_value{std::move(value)} {}

int Variable::value() const { return 0; }

std::string Variable::format() const { return std::string(""); }
