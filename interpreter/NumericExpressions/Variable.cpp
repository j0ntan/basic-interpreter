#include "Variable.h"

Variable::Variable(std::string name, int value)
    : var_name{name.empty() ? std::string("UNKNOWN") : std::move(name)},
      var_value{value} {}

int Variable::value() const { return var_value; }

std::string Variable::format() const { return var_name; }

std::string Variable::name() const { return var_name; }

void Variable::assign(const int &v) { var_value = v; }
