#ifndef ASSIGNVARIABLE_HPP
#define ASSIGNVARIABLE_HPP

#include "Command.h"

class AssignVariable : public Command {
public:
  AssignVariable();

  std::string format() const final;

  ~AssignVariable() final = default;
};

#endif
