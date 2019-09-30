#ifndef DIVISION_HPP
#define DIVISION_HPP

#include "BinaryExpression.h"

class Division final : public BinaryExpression {
public:
  explicit Division(const NumericExpression &left,
                    const NumericExpression &right);

  int value() const final;

  ~Division() final = default;
};

#endif
