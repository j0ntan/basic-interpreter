#ifndef ASSIGNARRAY_HPP
#define ASSIGNARRAY_HPP

#include "Command.h"

class AssignArray : public Command {
public:
  AssignArray();

  std::string format() const final;

  ~AssignArray() final = default;
};

#endif
