#ifndef EQUALS_HPP
#define EQUALS_HPP

#include "BooleanExpression.h"

class Equals final : public BooleanExpression {
public:
  explicit Equals(const NumericExpression &nexp1,
                  const NumericExpression &nexp2);

  bool value() const final;

  ~Equals() final = default;
};

#endif
