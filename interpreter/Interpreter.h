#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>
#include <string>

class Interpreter {
public:
  Interpreter(std::istream &in);
  ~Interpreter() = default;

  void write(std::ostream &out);

private:
  void parse(std::istream &in);

  std::string command;
};

#endif
