#ifndef EQUALS_HPP
#define EQUALS_HPP

#include "BooleanExpression.h"

class Equals final : public BooleanExpression {
public:
  explicit Equals(const NumericExpression *left,
                  const NumericExpression *right);

  bool value() const final;

  ~Equals() final = default;
};

#endif
