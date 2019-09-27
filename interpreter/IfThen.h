#ifndef IFTHEN_H
#define IFTHEN_H

#include "Command.h"

class BooleanExpression;

class IfThen : public Command {
public:
  IfThen(unsigned int line_number, const BooleanExpression &comparison,
         unsigned int jline);

  std::string format() const final;

  ~IfThen() final = default;
};

#endif
