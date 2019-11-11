#ifndef FORMATSPACING_HPP
#define FORMATSPACING_HPP

#include <string>

/**
 * @brief Removes leading & trailing whitespace in a string, and replaces each
 * continuous sequence of whitespace characters in the string with a single
 * space
 *
 * @param str The string to be modified
 * @return std::string The reduced-space string result
 */
std::string fix_spacing(const std::string &str);

#endif
