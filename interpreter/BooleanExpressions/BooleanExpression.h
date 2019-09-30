#ifndef BOOLEANEXPRESSION_HPP
#define BOOLEANEXPRESSION_HPP

#include "NumericExpression.h"
#include <string>

class BooleanExpression {
public:
  BooleanExpression(const NumericExpression &left,
                    const NumericExpression &right, const char operation_type)
      : left{left}, right{right}, operation{operation_type} {}

  virtual bool value() const = 0;
  std::string format() const {
    return left.format() + ' ' + operation + ' ' + right.format();
  }

  virtual ~BooleanExpression() = default;

protected:
  const NumericExpression &left;
  const NumericExpression &right;
  const char operation;
};

#endif
