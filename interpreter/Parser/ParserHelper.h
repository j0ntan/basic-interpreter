#ifndef PARSERHELPER_HPP
#define PARSERHELPER_HPP

#include <string>
#include <utility>

bool isNumericExpression(const std::string &str);
bool isInteger(const std::string &str);
bool isVariable(const std::string &str);
bool isArray(const std::string &str);
bool isBinaryExpression(const std::string &str);
std::string remove_surrounding_whitespace(const std::string &str);
std::pair<std::string, std::string> get_operands(const std::string &expression);

#endif
