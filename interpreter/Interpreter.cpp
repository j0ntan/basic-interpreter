#include "Interpreter.h"
#include <sstream>
#include <string>

Interpreter::Interpreter(std::istream &in) { this->parse(in); }

void Interpreter::parse(std::istream &in) {
  std::string line;
  while (getline(in, line)) {
    size_t line_number;
    std::stringstream stream(line);
    stream >> line_number;

    // Your code here
  }
}

void Interpreter::write(std::ostream &out) {}
