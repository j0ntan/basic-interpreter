#ifndef ASSIGNARRAY_HPP
#define ASSIGNARRAY_HPP

#include "Array.h"
#include "Command.h"
#include "NumericExpression.h"

class AssignArray : public Command {
public:
  AssignArray(unsigned int line_number, const Array &array,
              const NumericExpression &value);

  std::string format() const final;

  ~AssignArray() final = default;

private:
  const Array &array;
  const NumericExpression &value;
};

#endif
