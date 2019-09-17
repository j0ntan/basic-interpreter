#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include "Constant.h"
#include "NumericExpression.h"

class Variable final : public NumericExpression {
public:
  explicit Variable(std::string name, Constant value);

  int value() const final;
  std::string format() const final;

  ~Variable() final = default;

private:
  const std::string var_name;
  Constant var_value;
};

#endif
