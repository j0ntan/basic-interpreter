#ifndef ARRAY_H
#define ARRAY_H

#include "NumericExpression.h"

class Array : public NumericExpression {
public:
  int value() const final;
  std::string format() const final;

  ~Array() final = default;
};

#endif // HW2_ARRAY_H
