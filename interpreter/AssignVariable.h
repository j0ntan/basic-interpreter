#ifndef ASSIGNVARIABLE_HPP
#define ASSIGNVARIABLE_HPP

#include "Command.h"
#include "Variable.h"

class AssignVariable : public Command {
public:
  AssignVariable(unsigned int line_number, Variable v,
                 const NumericExpression &value);

  std::string format() const final;

  ~AssignVariable() final = default;
};

#endif
