#ifndef NUMERICEXPRESSION_HPP
#define NUMERICEXPRESSION_HPP

#include <string>

class NumericExpression {
public:
  virtual int value() const = 0;
  virtual std::string format() const = 0;

  virtual ~NumericExpression() = default;
};

#endif
