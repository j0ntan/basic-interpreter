#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "NumericExpression.h"

class Constant final : public NumericExpression {
public:
  explicit Constant(int n = 0);

  int value() const final;
  std::string format() const final;

  ~Constant() final = default;

private:
  const int val = 0;
};

#endif
