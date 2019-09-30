#ifndef MULTIPLICATION_HPP
#define MULTIPLICATION_HPP

#include "BinaryExpression.h"

class Multiplication final : public BinaryExpression {
public:
  explicit Multiplication(const NumericExpression &left,
                          const NumericExpression &right);

  int value() const final;

  ~Multiplication() final = default;
};

#endif
