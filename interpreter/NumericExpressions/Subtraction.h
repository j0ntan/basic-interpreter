#ifndef SUBTRACTION_HPP
#define SUBTRACTION_HPP

#include "BinaryExpression.h"

class Subtraction final : public BinaryExpression {
public:
  explicit Subtraction(const NumericExpression &nexp1,
                       const NumericExpression &nexp2);

  int value() const final;

  ~Subtraction() final = default;
};

#endif
