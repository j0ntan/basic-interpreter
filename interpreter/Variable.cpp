#include "Variable.h"
#include <utility>

Variable::Variable(std::string name, Constant value)
    : var_name{name.empty() ? std::string("UNKNOWN") : std::move(name)},
      var_value{std::move(value)} {}

int Variable::value() const { return var_value.value(); }

std::string Variable::format() const { return var_name; }

std::string Variable::name() const { return var_name; }

void Variable::assign(const Variable &v) { var_value = v.var_value; }
