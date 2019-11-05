#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include "NumericExpression.hpp"

class Variable final : public NumericExpression {
public:
  explicit Variable(std::string name = std::string("UNKNOWN"), int value = 0);

  int value() const final;
  std::string format() const final;

  std::string name() const;
  void assign(const int &new_value);

  ~Variable() final = default;

private:
  const std::string variable_name;
  int variable_value;
};

#endif
