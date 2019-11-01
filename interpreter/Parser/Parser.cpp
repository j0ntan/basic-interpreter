#include "Parser.h"
#include "Addition.h"
#include "AssignArray.h"
#include "AssignVariable.h"
#include "Constant.h"
#include "Division.h"
#include "End.h"
#include "Equals.h"
#include "GoSub.h"
#include "Goto.h"
#include "IfThen.h"
#include "LessThan.h"
#include "Multiplication.h"
#include "ParserHelper.h"
#include "Print.h"
#include "Return.h"
#include "Subtraction.h"
#include "Variable.h"
#include <cctype>

std::string findNextExpression(const std::string &cmd) {
  size_t offset = cmd.find_first_not_of(" \t");
  size_t begins = offset == std::string::npos ? 0 : offset, ends = begins;

  if (std::isdigit(cmd[begins]) || cmd[begins] == '-')
    ends = cmd.find_first_not_of("-0123456789", begins);
  else if (std::isupper(cmd[begins]))
    ends = cmd.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ", begins);
  else if (cmd[begins] == '(') {
    int nested_count = 0;
    do {
      if (cmd[ends] == '(')
        ++nested_count;
      else if (cmd[ends] == ')')
        --nested_count;
    } while (++ends < cmd.size() && nested_count != 0);
  }
  return cmd.substr(begins, ends - begins);
}

bool has_line_number(const std::string &cmd) {
  const size_t non_whitespace_pos = cmd.find_first_not_of(" \t");
  return cmd.find_first_of("0123456789", non_whitespace_pos) ==
         non_whitespace_pos;
}

static bool has_keyword(const std::string &cmd, const std::string &keyword) {
  const auto keyword_pos = cmd.find(keyword);
  const auto found_keyword = keyword_pos != std::string::npos;
  const auto has_left_whitespace =
      found_keyword &&
      cmd.find_last_of(" \t", keyword_pos - 1) == keyword_pos - 1;
  const auto has_right_whitespace =
      found_keyword &&
      cmd.find_first_of(" \t", keyword_pos + keyword.length()) ==
          keyword_pos + keyword.length();
  return found_keyword && has_left_whitespace && has_right_whitespace;
}

bool is_print_cmd(const std::string &cmd) {
  if (has_keyword(cmd, "PRINT")) {
    const auto after_print_pos = cmd.find("PRINT") + 5;
    const auto value = cmd.substr(after_print_pos);
    return isNumericExpression(value);
  }
  return false;
}

bool is_assign_variable_cmd(const std::string &cmd) {
  if (has_keyword(cmd, "LET")) {
    const auto after_let_pos = cmd.find("LET") + 3;
    const auto variable = findNextExpression(cmd.substr(after_let_pos));
    const auto after_variable_pos = cmd.find(variable) + variable.length();
    const auto value = variable.empty()
                           ? variable
                           : findNextExpression(cmd.substr(after_variable_pos));
    return !variable.empty() && isVariable(variable) && !value.empty() &&
           isNumericExpression(value);
  }
  return false;
}

size_t find_matching_bracket(size_t left_bracket_pos, const std::string &cmd) {
  for (size_t i = left_bracket_pos, nested_count = 0; i < cmd.size(); ++i) {
    const auto &this_char = cmd[i];
    if (this_char == '[' || this_char == '(')
      ++nested_count;
    else if (this_char == ']' || this_char == ')')
      --nested_count;
    if (nested_count == 0)
      return i;
  }
  return std::string::npos;
}

bool is_assign_array_cmd(const std::string &cmd) {
  const auto left_bracket_pos = cmd.find('[');
  const auto right_bracket_pos = find_matching_bracket(left_bracket_pos, cmd);
  const auto has_bracket_pair = left_bracket_pos != std::string::npos &&
                                right_bracket_pos != std::string::npos;
  if (has_keyword(cmd, "LET") && has_bracket_pair) {
    const auto after_let_pos = cmd.find("LET") + 3;
    const auto variable = findNextExpression(cmd.substr(after_let_pos));
    const auto index = cmd.substr(left_bracket_pos + 1,
                                  right_bracket_pos - left_bracket_pos - 1);
    const auto value = cmd.substr(right_bracket_pos + 1);
    return !variable.empty() && isVariable(variable) && !index.empty() &&
           isNumericExpression(index) && !value.empty() &&
           isNumericExpression(value);
  }
  return false;
}

bool is_goto_cmd(const std::string &cmd) {
  if (has_keyword(cmd, "GOTO")) {
    const auto after_goto_pos = cmd.find("GOTO") + 4;
    const auto jline = findNextExpression(cmd.substr(after_goto_pos));
    return !jline.empty() && isInteger(jline) && jline[0] != '-';
  }
  return false;
}

bool is_if_then_cmd(const std::string &cmd) {
  const auto if_pos = cmd.find("IF"), then_pos = cmd.find("THEN");
  if (has_keyword(cmd, "IF") && has_keyword(cmd, "THEN") && if_pos < then_pos) {
    const auto in_between_if_then_str =
        cmd.substr(if_pos + 2, then_pos - (if_pos + 2));
    const auto boolean = remove_surrounding_whitespace(in_between_if_then_str);
    const auto jline = findNextExpression(cmd.substr(then_pos + 4));
    return isBooleanExpression(boolean) && !jline.empty() && isInteger(jline) &&
           jline[0] != '-';
  }
  return false;
}

bool is_gosub_cmd(const std::string &cmd) {
  if (has_keyword(cmd, "GOSUB")) {
    const auto after_gosub_pos = cmd.find("GOSUB") + 5;
    const auto jline = findNextExpression(cmd.substr(after_gosub_pos));
    return !jline.empty() && isInteger(jline) && jline[0] != '-';
  }
  return false;
}

static bool has_terminating_keyword(const std::string &cmd,
                                    const std::string &keyword) {
  const auto keyword_pos = cmd.find(keyword);
  const auto found_keyword = keyword_pos != std::string::npos;
  const auto has_left_whitespace =
      found_keyword &&
      cmd.find_last_of(" \t", keyword_pos - 1) == keyword_pos - 1;
  const auto is_terminator =
      found_keyword && keyword_pos + keyword.length() == cmd.length();
  return found_keyword && has_left_whitespace && is_terminator;
}

bool is_return_cmd(const std::string &cmd) {
  return has_terminating_keyword(cmd, "RETURN");
}

bool is_end_cmd(const std::string &cmd) {
  return has_terminating_keyword(cmd, "END");
}

NumericExpression *numericExpressionGenerator(std::string expression) {
  expression = remove_surrounding_whitespace(expression);
  if (isInteger(expression))
    return new Constant(std::stoi(expression));
  else if (isVariable(expression))
    return new Variable(expression);
  else if (isBinaryExpression(expression)) {
    const auto operands =
        get_operands(expression.substr(1, expression.length() - 2));
    const auto operator_position = expression.find_first_of(
        "+-*/", expression.find(operands.first) + operands.first.length());
    switch (expression[operator_position]) {
    case '+':
      return new Addition(numericExpressionGenerator(operands.first),
                          numericExpressionGenerator(operands.second));
    case '-':
      return new Subtraction(numericExpressionGenerator(operands.first),
                             numericExpressionGenerator(operands.second));
    case '*':
      return new Multiplication(numericExpressionGenerator(operands.first),
                                numericExpressionGenerator(operands.second));
    case '/':
      return new Division(numericExpressionGenerator(operands.first),
                          numericExpressionGenerator(operands.second));
    }
  }

  return nullptr;
}

static unsigned int get_line_number(const std::string &command) {
  const auto line_number_begins = command.find_first_not_of(" \t");
  const auto line_number_ends =
      command.find_first_of(" \t", line_number_begins);
  return std::stoi(command.substr(line_number_begins,
                                  line_number_ends - line_number_begins + 1));
}

static Variable *get_variable_expression(const std::string &command) {
  const auto name_begins = command.find("LET") + 4;
  const auto name_str = findNextExpression(command.substr(name_begins));
  return new Variable(name_str);
}

static NumericExpression *
get_proceeding_expression(const std::string &command,
                          const std::string &keyword) {
  const auto keyword_position = command.find(keyword);
  const auto expression_str =
      findNextExpression(command.substr(keyword_position + keyword.length()));
  return numericExpressionGenerator(expression_str);
}

static NumericExpression *get_array_index(const std::string &command) {
  return get_proceeding_expression(command, "[");
}

static NumericExpression *get_array_assigned_value(const std::string &command) {
  const auto left_bracket_position = command.find('[');
  const auto right_bracket_position =
      find_matching_bracket(left_bracket_position, command);
  return numericExpressionGenerator(command.substr(right_bracket_position + 1));
}

BooleanExpression *get_boolean_expression(const std::string &command) {
  const auto boolean_begins = command.find("IF") + 2;
  const auto boolean_length = command.find("THEN") - boolean_begins;
  const auto boolean_str = remove_surrounding_whitespace(
      command.substr(boolean_begins, boolean_length));
  return booleanGenerator(boolean_str);
}

Command *commandGenerator(const std::string &command) {
  if (!has_line_number(command))
    return nullptr;
  else {
    const auto line_number = get_line_number(command);
    if (is_print_cmd(command)) {
      const auto expression = get_proceeding_expression(command, "PRINT");
      return new Print(line_number, expression);
    } else if (is_assign_variable_cmd(command)) {
      const auto name = get_variable_expression(command);
      const auto expression = get_proceeding_expression(command, name->name());
      return new AssignVariable(line_number, name, expression);
    } else if (is_assign_array_cmd(command)) {
      const auto name = get_variable_expression(command);
      const auto index = get_array_index(command);
      const auto value = get_array_assigned_value(command);
      return new AssignArray(line_number, name, index, value);
    } else if (is_goto_cmd(command)) {
      const auto jline = std::stoi(command.substr(command.find("GOTO") + 4));
      return new Goto(line_number, jline);
    } else if (is_if_then_cmd(command)) {
      const auto boolean_expression = get_boolean_expression(command);
      const auto jline = std::stoi(command.substr(command.find("THEN") + 4));
      return new IfThen(line_number, boolean_expression, jline);
    } else if (is_gosub_cmd(command)) {
      const auto jline = std::stoi(command.substr(command.find("GOSUB") + 5));
      return new GoSub(line_number, jline);
    } else if (is_return_cmd(command))
      return new Return(line_number);
    else if (is_end_cmd(command))
      return new End(line_number);
  }

  return nullptr;
}

BooleanExpression *booleanGenerator(const std::string &command) {
  const auto operator_position = command.find_first_of("<=>");
  const auto left_expression =
      numericExpressionGenerator(command.substr(0, operator_position));
  const auto right_expression =
      numericExpressionGenerator(command.substr(operator_position + 1));
  if (command[operator_position] == '<')
    return new LessThan(left_expression, right_expression);
  else if (command[operator_position] == '>')
    return new LessThan(right_expression, left_expression);
  else
    return new Equals(left_expression, right_expression);
}
