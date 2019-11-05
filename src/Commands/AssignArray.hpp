#ifndef ASSIGNARRAY_HPP
#define ASSIGNARRAY_HPP

#include "Command.hpp"
#include <memory>

class NumericExpression;
class Variable;

class AssignArray : public Command {
public:
  AssignArray(unsigned int line_number, const Variable *name,
              const NumericExpression *index, const NumericExpression *value);

  std::string format() const final;

  ~AssignArray() final = default;

private:
  const std::unique_ptr<const Variable> name;
  const std::unique_ptr<const NumericExpression> index;
  const std::unique_ptr<const NumericExpression> value;
};

#endif
