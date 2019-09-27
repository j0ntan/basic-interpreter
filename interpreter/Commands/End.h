#ifndef END_HPP
#define END_HPP

#include "Command.h"

class End : public Command {
public:
  End(unsigned int line_number);

  std::string format() const final;

  ~End() final = default;
};

#endif
