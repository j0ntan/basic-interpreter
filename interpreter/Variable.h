#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include "NumericExpression.h"

class Variable final : public NumericExpression {
public:
  int value() const final;
  std::string format() const final;

  ~Variable() final = default;
};

#endif
