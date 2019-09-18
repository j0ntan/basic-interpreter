#ifndef BOOLEANEXPRESSION_HPP
#define BOOLEANEXPRESSION_HPP

#include "NumericExpression.h"
#include <string>

class BooleanExpression {
public:
  BooleanExpression(const NumericExpression &nexp1,
                    const NumericExpression &nexp2, const char operation_type)
      : num1{nexp1}, num2{nexp2}, operation{operation_type} {}

  virtual bool value() const = 0;
  std::string format() const {
    return num1.format() + ' ' + operation + ' ' + num2.format();
  }

  virtual ~BooleanExpression() = default;

protected:
  const NumericExpression &num1;
  const NumericExpression &num2;
  const char operation;
};

#endif
