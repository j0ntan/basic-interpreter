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

TEST_F(InterpreterTest, writeComplexPrintCommand) {
  interpret_command("1 PRINT ((A + B) + (1 + 2))\n",
                    "1 PRINT ((A + B) + (1 + 2))\n");
}

TEST_F(InterpreterTest, writeTwoSimplePrintCommands) {
  interpret_command("1 PRINT 1\n2 PRINT 2\n", "1 PRINT 1\n2 PRINT 2\n");
}

TEST_F(InterpreterTest, ignoreWritingNonCommandString) {
  interpret_command("1 PRINT 1\n2 PINT 2\n", "1 PRINT 1\n");
}

TEST_F(InterpreterTest, writeCorrectlyFormattedPrintCommand) {
  interpret_command("1 PRINT (1+2)\n", "1 PRINT (1 + 2)\n");
}

TEST_F(InterpreterTest, writeAssignVariableCommand) {
  interpret_command("1 LET X 123\n", "1 LET X 123\n");
}

TEST_F(InterpreterTest, writeAssignArrayCommand) {
  interpret_command("1 LET X[123] 123\n", "1 LET X[123] 123\n");
}

TEST_F(InterpreterTest, writeGotoCommand) {
  interpret_command("1 GOTO  123\n", "1 GOTO <123>\n");
}
