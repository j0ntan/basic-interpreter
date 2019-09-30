#ifndef ASSIGNVARIABLE_HPP
#define ASSIGNVARIABLE_HPP

#include "Command.h"
#include "Variable.h"

class AssignVariable : public Command {
public:
  AssignVariable(unsigned int line_number, const Variable &variable,
                 const NumericExpression &value);

  std::string format() const final;

  ~AssignVariable() final = default;

private:
  const Variable &variable;
  const NumericExpression &value;
};

#endif
