#ifndef LESSTHAN_HPP
#define LESSTHAN_HPP

#include "BooleanExpression.hpp"

class LessThan final : public BooleanExpression {
public:
  explicit LessThan(const NumericExpression *left,
                    const NumericExpression *right);

  bool value() const final;

  ~LessThan() final = default;
};

#endif
