#ifndef BOOLEANEXPRESSION_HPP
#define BOOLEANEXPRESSION_HPP

#include <Expressions/Numeric/NumericExpression.hpp>
#include <memory>
#include <string>

class BooleanExpression {
public:
  BooleanExpression(const NumericExpression *left,
                    const NumericExpression *right, const char operation_type)
      : left{left}, right{right}, operation{operation_type} {}

  virtual bool value() const = 0;
  std::string format() const {
    return left->format() + ' ' + operation + ' ' + right->format();
  }

  virtual ~BooleanExpression() = default;

protected:
  const std::unique_ptr<const NumericExpression> left;
  const std::unique_ptr<const NumericExpression> right;
  const char operation;
};

#endif
