add_library(ConstantTests Constant.cpp)
target_link_libraries(ConstantTests PRIVATE Constant gtest)
add_executable(test_Constant $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:ConstantTests>)
target_link_libraries(test_Constant PRIVATE ConstantTests)

add_library(VariableTests Variable.cpp)
target_link_libraries(VariableTests PRIVATE Variable gtest)
add_executable(test_Variable $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:VariableTests>)
target_link_libraries(test_Variable PRIVATE VariableTests)

add_library(AdditionTests Addition.cpp)
target_link_libraries(AdditionTests PRIVATE Addition Variable Constant gtest)
add_executable(test_Addition $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:AdditionTests>)
target_link_libraries(test_Addition PRIVATE AdditionTests)

add_library(SubtractionTests Subtraction.cpp)
target_link_libraries(SubtractionTests PRIVATE Subtraction Variable Constant gtest)
add_executable(test_Subtraction $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:SubtractionTests>)
target_link_libraries(test_Subtraction PRIVATE SubtractionTests)

add_library(MultiplicationTests Multiplication.cpp)
target_link_libraries(MultiplicationTests PRIVATE Multiplication Variable Constant gtest)
add_executable(test_Multiplication $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:MultiplicationTests>)
target_link_libraries(test_Multiplication PRIVATE MultiplicationTests)

add_library(DivisionTests Division.cpp)
target_link_libraries(DivisionTests PRIVATE Division Variable Constant gtest)
add_executable(test_Division $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:DivisionTests>)
target_link_libraries(test_Division PRIVATE DivisionTests)

add_library(LessThanTests LessThan.cpp)
target_link_libraries(LessThanTests PRIVATE LessThan Addition Variable Constant gtest)
add_executable(test_LessThan $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:LessThanTests>)
target_link_libraries(test_LessThan PRIVATE LessThanTests)

add_library(EqualsTests Equals.cpp)
target_link_libraries(EqualsTests PRIVATE Equals Addition Variable Constant gtest)
add_executable(test_Equals $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:EqualsTests>)
target_link_libraries(test_Equals PRIVATE EqualsTests)

add_library(PrintTests Print.cpp)
target_link_libraries(PrintTests PRIVATE Print Addition Variable Constant gtest)
add_executable(test_Print $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:PrintTests>)
target_link_libraries(test_Print PRIVATE PrintTests)

add_library(AssignVariableTests AssignVariable.cpp)
target_link_libraries(AssignVariableTests PRIVATE AssignVariable Variable Constant gtest)
add_executable(test_AssignVariable $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:AssignVariableTests>)
target_link_libraries(test_AssignVariable PRIVATE AssignVariableTests)

add_library(AssignArrayTests AssignArray.cpp)
target_link_libraries(AssignArrayTests PRIVATE AssignArray Variable Constant gtest)
add_executable(test_AssignArray $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:AssignArrayTests>)
target_link_libraries(test_AssignArray PRIVATE AssignArrayTests)

add_library(GotoTests Goto.cpp)
target_link_libraries(GotoTests PRIVATE Goto gtest)
add_executable(test_Goto $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:GotoTests>)
target_link_libraries(test_Goto PRIVATE GotoTests)

add_library(IfThenTests IfThen.cpp)
target_link_libraries(IfThenTests PRIVATE IfThen LessThan Constant gtest)
add_executable(test_IfThen $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:IfThenTests>)
target_link_libraries(test_IfThen PRIVATE IfThenTests)

add_library(GoSubTests GoSub.cpp)
target_link_libraries(GoSubTests PRIVATE GoSub gtest)
add_executable(test_GoSub $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:GoSubTests>)
target_link_libraries(test_GoSub PRIVATE GoSubTests)

add_library(ReturnTests Return.cpp)
target_link_libraries(ReturnTests PRIVATE Return gtest)
add_executable(test_Return $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:ReturnTests>)
target_link_libraries(test_Return PRIVATE ReturnTests)

add_library(EndTests End.cpp)
target_link_libraries(EndTests PRIVATE End gtest)
add_executable(test_End $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:EndTests>)
target_link_libraries(test_End PRIVATE EndTests)

add_library(ParserHelperTests ParserHelper.cpp)
target_link_libraries(ParserHelperTests PRIVATE ParserHelper gtest)
add_executable(test_ParserHelper $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:ParserHelperTests>)
target_link_libraries(test_ParserHelper PRIVATE ParserHelperTests)

add_library(ParserTests Parser.cpp)
target_link_libraries(ParserTests PRIVATE Parser Command BooleanExpression
        NumericExpression gtest)
add_executable(test_Parser $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:ParserTests>)
target_link_libraries(test_Parser PRIVATE ParserTests)

add_library(InterpreterTests Interpreter.cpp)
target_link_libraries(InterpreterTests PRIVATE Interpreter gtest)
add_executable(test_Interpreter $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:InterpreterTests>)
target_link_libraries(test_Interpreter PRIVATE InterpreterTests)

add_executable(test_ALL $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:ConstantTests>
        $<TARGET_OBJECTS:VariableTests> $<TARGET_OBJECTS:AdditionTests>
        $<TARGET_OBJECTS:SubtractionTests> $<TARGET_OBJECTS:MultiplicationTests>
        $<TARGET_OBJECTS:DivisionTests> $<TARGET_OBJECTS:LessThanTests>
        $<TARGET_OBJECTS:EqualsTests> $<TARGET_OBJECTS:PrintTests>
        $<TARGET_OBJECTS:AssignVariableTests> $<TARGET_OBJECTS:AssignArrayTests>
        $<TARGET_OBJECTS:GotoTests> $<TARGET_OBJECTS:IfThenTests>
        $<TARGET_OBJECTS:GoSubTests> $<TARGET_OBJECTS:ReturnTests>
        $<TARGET_OBJECTS:EndTests> $<TARGET_OBJECTS:ParserHelperTests>
        $<TARGET_OBJECTS:ParserTests> $<TARGET_OBJECTS:InterpreterTests>
        )
target_link_libraries(test_ALL PRIVATE Interpreter gtest)
