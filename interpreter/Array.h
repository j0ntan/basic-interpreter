#ifndef ARRAY_H
#define ARRAY_H

#include "NumericExpression.h"

class Array : public NumericExpression {
public:
  Array(std::string name, const NumericExpression &index);

  int value() const final;
  std::string format() const final;

  std::string name() const;

  ~Array() final = default;

private:
  const std::string array_name;
};

#endif // HW2_ARRAY_H
