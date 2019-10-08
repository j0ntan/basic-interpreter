#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

std::string findNextExpression(const std::string &cmd);
bool has_line_number(const std::string &cmd);
bool is_print_cmd(const std::string &cmd);
bool is_assign_variable_cmd(const std::string &cmd);
bool is_assign_array_cmd(const std::string &cmd);
bool is_goto_cmd(const std::string &cmd);
bool is_if_then_cmd(const std::string &cmd);

#endif
