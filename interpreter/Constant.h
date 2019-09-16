#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "NumericExpression.h"

class Constant final : public NumericExpression {
public:
  int value() const final;
  std::string format() const final;

  ~Constant() final = default;
};

#endif
