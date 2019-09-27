#ifndef END_HPP
#define END_HPP

#include "Command.h"

class End : public Command {
public:
  End();

  std::string format() const final;

  ~End() final = default;
};

#endif
