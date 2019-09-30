#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

bool isNumericExpression(const std::string &str);
bool isInteger(const std::string &str);
bool isVariable(const std::string &str);
bool isArray(const std::string &str);
bool isBinaryExpression(const std::string &str);
std::string remove_surrounding_whitespace(const std::string &str);

#endif
