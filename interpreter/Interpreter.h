#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "Command.h"
#include <iostream>
#include <memory>
#include <vector>

class Interpreter {
public:
  Interpreter(std::istream &in);
  ~Interpreter() = default;

  void write(std::ostream &out);

private:
  void parse(std::istream &in);

  std::vector<std::unique_ptr<Command>> commands;
};

#endif
