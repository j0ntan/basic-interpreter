#ifndef GOSUB_HPP
#define GOSUB_HPP

#include "Command.h"

class GoSub : public Command {
public:
  GoSub(unsigned int line_number, unsigned int jline);

  std::string format() const final;

  ~GoSub() final = default;

private:
  const unsigned int jline;
};

#endif
