#ifndef PRINT_HPP
#define PRINT_HPP

#include "Command.h"

class NumericExpression;

class Print final : public Command {
public:
  Print(unsigned int line_number, const NumericExpression &expression);

  std::string format() const final;

  ~Print() final = default;

private:
  const NumericExpression &expression;
};

#endif
