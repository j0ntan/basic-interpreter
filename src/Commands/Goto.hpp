#ifndef GOTO_HPP
#define GOTO_HPP

#include "Command.hpp"

class Goto : public Command {
public:
  Goto(unsigned int line_number, unsigned int jline);

  std::string format() const final;

  ~Goto() final = default;

private:
  const unsigned int jline;
};

#endif
