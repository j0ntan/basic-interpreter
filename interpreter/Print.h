#ifndef PRINT_HPP
#define PRINT_HPP

#include "Command.h"

class Print final : public Command {
public:
  Print();

  std::string format() const final;

  ~Print() final = default;
};

#endif
