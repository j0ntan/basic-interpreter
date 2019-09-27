#ifndef GOTO_HPP
#define GOTO_HPP

#include "Command.h"

class Goto : public Command {
public:
  Goto(unsigned int line_number, unsigned int jline);

  std::string format() const final;

  ~Goto() final = default;
};

#endif
