#ifndef RETURN_HPP
#define RETURN_HPP

#include "Command.h"

class Return : public Command {
public:
  Return(unsigned int line_number);

  std::string format() const final;

  ~Return() final = default;
};

#endif
