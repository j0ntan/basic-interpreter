#include "FormatStringSpacing.hpp"

std::string fix_spacing(const std::string &str) {
  const auto first_char_position = str.find_first_not_of(" \t");
  const auto last_char_position = str.find_last_not_of(" \t");
  return str.substr(first_char_position,
                    last_char_position - first_char_position + 1);
}
