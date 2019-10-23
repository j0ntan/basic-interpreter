#ifndef ASSIGNVARIABLE_HPP
#define ASSIGNVARIABLE_HPP

#include "Command.h"
#include <memory>

class NumericExpression;
class Variable;

class AssignVariable : public Command {
public:
  AssignVariable(unsigned int line_number, const Variable *variable,
                 const NumericExpression *value);

  std::string format() const final;

  ~AssignVariable() final = default;

private:
  const std::unique_ptr<const Variable> variable;
  const std::unique_ptr<const NumericExpression> value;
};

#endif
