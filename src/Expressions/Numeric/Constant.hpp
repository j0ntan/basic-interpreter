#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "NumericExpression.hpp"

class Constant final : public NumericExpression {
public:
  explicit Constant(int value = 0);

  int value() const final;
  std::string format() const final;

  ~Constant() final = default;

private:
  const int integral_value = 0;
};

#endif
