#include "Interpreter.h"
#include <sstream>

Interpreter::Interpreter(std::istream &in) { this->parse(in); }

void Interpreter::parse(std::istream &in) {
  std::string line;
  while (getline(in, line)) {
    size_t line_number;
    std::stringstream stream(line);
    stream >> line_number;

    commands.push_back(line);
  }
}

void Interpreter::write(std::ostream &out) {
  for (const auto &command : commands)
    out << command << '\n';
}
