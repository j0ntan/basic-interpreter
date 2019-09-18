#ifndef DIVISION_HPP
#define DIVISION_HPP

#include "BinaryExpression.h"

class Division final : public BinaryExpression {
public:
  explicit Division(const NumericExpression &nexp1,
                    const NumericExpression &nexp2);

  int value() const final;

  ~Division() final = default;
};

#endif
