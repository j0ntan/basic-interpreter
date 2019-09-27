#ifndef ASSIGNARRAY_HPP
#define ASSIGNARRAY_HPP

#include "Command.h"

class Array;
class NumericExpression;

class AssignArray : public Command {
public:
  AssignArray(unsigned int line_number, const Array &array,
              const NumericExpression &value);

  std::string format() const final;

  ~AssignArray() final = default;
};

#endif
