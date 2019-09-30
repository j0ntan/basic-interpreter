#include "Variable.h"

Variable::Variable(std::string name, int value)
    : variable_name{name.empty() ? std::string("UNKNOWN") : std::move(name)},
      variable_value{value} {}

int Variable::value() const { return variable_value; }

std::string Variable::format() const { return variable_name; }

std::string Variable::name() const { return variable_name; }

void Variable::assign(const int &new_value) { variable_value = new_value; }
