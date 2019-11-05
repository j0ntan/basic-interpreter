#include <Commands/Command.hpp>
#include <Interpreter/Interpreter.hpp>
#include <Parser/Parser.hpp>
#include <string>

Interpreter::Interpreter(std::istream &in) { this->parse(in); }

Interpreter::~Interpreter() = default;

void Interpreter::parse(std::istream &in) {
  std::string line;
  while (getline(in, line)) {
    const bool is_command = is_print_cmd(line) ||
                            is_assign_variable_cmd(line) ||
                            is_assign_array_cmd(line) || is_goto_cmd(line) ||
                            is_if_then_cmd(line) || is_gosub_cmd(line) ||
                            is_return_cmd(line) || is_end_cmd(line);
    if (is_command)
      commands.emplace_back(commandGenerator(line));
  }
}

void Interpreter::write(std::ostream &out) {
  for (const auto &command : commands)
    out << command->format() << '\n';
}
