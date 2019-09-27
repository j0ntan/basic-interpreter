#ifndef GOSUB_HPP
#define GOSUB_HPP

#include "Command.h"

class GoSub : public Command {
public:
  GoSub();

  std::string format() const final;

  ~GoSub() final = default;
};

#endif
