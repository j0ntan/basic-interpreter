#include "FormatStringSpacing.hpp"

std::string fix_spacing(const std::string &str) {
  std::string result;
  size_t word_begins_position = str.find_first_not_of(" \t"),
         word_ends_position;
  while (word_begins_position < std::string::npos) {
    word_ends_position = str.find_first_of(" \t", word_begins_position);
    std::string word;
    if (word_ends_position == std::string::npos) {
      word = str.substr(word_begins_position);
      word_begins_position = std::string::npos;
    } else {
      word = str.substr(word_begins_position,
                        word_ends_position - word_begins_position);
      word_begins_position = str.find_first_not_of(" \t", ++word_ends_position);
    }
    result.append(word);
    if (word_begins_position != std::string::npos)
      result.push_back(' ');
  }
  return result;
}
