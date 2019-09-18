#ifndef LESSTHAN_HPP
#define LESSTHAN_HPP

#include "BooleanExpression.h"

class LessThan final : public BooleanExpression {
public:
  explicit LessThan(const NumericExpression &nexp1,
                    const NumericExpression &nexp2);

  bool value() const final;

  ~LessThan() final = default;
};

#endif
