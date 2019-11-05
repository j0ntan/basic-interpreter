#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>
#include <memory>
#include <vector>

class Command;

class Interpreter {
public:
  Interpreter(std::istream &in);
  ~Interpreter();

  void write(std::ostream &out);

private:
  void parse(std::istream &in);

  std::vector<std::unique_ptr<Command>> commands;
};

#endif
