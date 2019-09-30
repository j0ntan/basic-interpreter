#ifndef ADDITION_HPP
#define ADDITION_HPP

#include "BinaryExpression.h"

class Addition final : public BinaryExpression {
public:
  explicit Addition(const NumericExpression &left,
                    const NumericExpression &right);

  int value() const final;

  ~Addition() final = default;
};

#endif
