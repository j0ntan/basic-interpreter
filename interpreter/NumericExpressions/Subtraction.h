#ifndef SUBTRACTION_HPP
#define SUBTRACTION_HPP

#include "BinaryExpression.h"

class Subtraction final : public BinaryExpression {
public:
  explicit Subtraction(const NumericExpression &left,
                       const NumericExpression &right);

  int value() const final;

  ~Subtraction() final = default;
};

#endif
