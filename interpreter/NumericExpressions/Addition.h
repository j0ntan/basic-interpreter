#ifndef ADDITION_HPP
#define ADDITION_HPP

#include "BinaryExpression.h"

class Addition final : public BinaryExpression {
public:
  explicit Addition(const NumericExpression &nexp1,
                    const NumericExpression &nexp2);

  int value() const final;

  ~Addition() final = default;
};

#endif
