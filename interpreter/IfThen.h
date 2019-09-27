#ifndef IFTHEN_H
#define IFTHEN_H

#include "Command.h"

class IfThen : public Command {
public:
  IfThen();

  std::string format() const final;

  ~IfThen() final = default;
};

#endif
