#ifndef GOTO_HPP
#define GOTO_HPP

#include "Command.h"

class Goto : public Command {
public:
  Goto();

  std::string format() const final;

  ~Goto() final = default;
};

#endif
