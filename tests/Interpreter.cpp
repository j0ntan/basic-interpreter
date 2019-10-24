#include "Interpreter.h"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

class InterpreterTest : public ::testing::Test {
protected:
  std::stringstream input_stream, output_stream;

  void interpret_command(const std::string &input_command_str,
                         const std::string &expected_str) {
    input_stream << input_command_str;
    Interpreter interpreter(input_stream);
    interpreter.write(output_stream);
    ASSERT_EQ(output_stream.str(), expected_str);
  }
};

TEST_F(InterpreterTest, writeSimplePrintCommand) {
  interpret_command("1 PRINT 1\n", "1 PRINT 1\n");
}
