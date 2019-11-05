#ifndef BINARYEXPRESSION_HPP
#define BINARYEXPRESSION_HPP

#include "NumericExpression.hpp"
#include <memory>

class BinaryExpression : public NumericExpression {
public:
  BinaryExpression(const NumericExpression *left,
                   const NumericExpression *right, const char operation_type)
      : left{left}, right{right}, operation{operation_type} {}

  int value() const override = 0;
  std::string format() const final {
    return '(' + left->format() + ' ' + operation + ' ' + right->format() + ')';
  }

  ~BinaryExpression() override = default;

protected:
  const std::unique_ptr<const NumericExpression> left;
  const std::unique_ptr<const NumericExpression> right;
  const char operation;
};

#endif
