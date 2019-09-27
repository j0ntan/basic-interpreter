#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Command {
public:
  Command(unsigned int line_number) : line_num{line_number} {}

  virtual std::string format() const = 0;
  unsigned int line() const { return line_num; }

  virtual ~Command() = default;

protected:
  const unsigned int line_num;
};

#endif
