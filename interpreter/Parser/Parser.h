#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

std::string findNextExpression(const std::string &cmd);
bool has_line_number(const std::string &cmd);

#endif
