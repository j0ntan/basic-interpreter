#ifndef BINARYEXPRESSION_HPP
#define BINARYEXPRESSION_HPP

#include "NumericExpression.h"

class BinaryExpression : public NumericExpression {
public:
  BinaryExpression(const NumericExpression &nexp1,
                   const NumericExpression &nexp2, const char operation_type)
      : num1{nexp1}, num2{nexp2}, operation{operation_type} {}

  virtual int value() const = 0;
  std::string format() const final {
    return '(' + num1.format() + ' ' + operation + ' ' + num2.format() + ')';
  }

  virtual ~BinaryExpression() = default;

protected:
  const NumericExpression &num1;
  const NumericExpression &num2;
  const char operation;
};

#endif
