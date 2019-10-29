#include "Interpreter.h"
#include "Parser.h"
#include <sstream>

Interpreter::Interpreter(std::istream &in) { this->parse(in); }

void Interpreter::parse(std::istream &in) {
  std::string line;
  while (getline(in, line)) {
    size_t line_number;
    std::stringstream stream(line);
    stream >> line_number;

    if (is_print_cmd(line) || is_assign_variable_cmd(line))
      commands.emplace_back(commandGenerator(line));
  }
}

void Interpreter::write(std::ostream &out) {
  for (const auto &command : commands)
    out << command->format() << '\n';
}
