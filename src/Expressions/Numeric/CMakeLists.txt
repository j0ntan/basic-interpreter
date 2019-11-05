add_library(Constant Constant.cpp)
add_library(ConstantTests Constant.test.cpp)
target_link_libraries(ConstantTests PRIVATE Constant gtest)
add_executable(test_Constant $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:ConstantTests>)
target_link_libraries(test_Constant ConstantTests)

add_library(Variable Variable.cpp)
add_library(VariableTests Variable.test.cpp)
target_link_libraries(VariableTests PRIVATE Variable gtest)
add_executable(test_Variable $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:VariableTests>)
target_link_libraries(test_Variable PRIVATE VariableTests)

add_library(Addition Addition.cpp)
add_library(AdditionTests Addition.test.cpp)
target_link_libraries(AdditionTests PRIVATE Addition Variable Constant gtest)
add_executable(test_Addition $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:AdditionTests>)
target_link_libraries(test_Addition PRIVATE AdditionTests)

add_library(Subtraction Subtraction.cpp)
add_library(SubtractionTests Subtraction.test.cpp)
target_link_libraries(SubtractionTests PRIVATE Subtraction Variable Constant gtest)
add_executable(test_Subtraction $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:SubtractionTests>)
target_link_libraries(test_Subtraction PRIVATE SubtractionTests)

add_library(Multiplication Multiplication.cpp)
add_library(MultiplicationTests Multiplication.test.cpp)
target_link_libraries(MultiplicationTests PRIVATE Multiplication Variable Constant gtest)
add_executable(test_Multiplication $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:MultiplicationTests>)
target_link_libraries(test_Multiplication PRIVATE MultiplicationTests)

add_library(Division Division.cpp)
add_library(DivisionTests Division.test.cpp)
target_link_libraries(DivisionTests PRIVATE Division Variable Constant gtest)
add_executable(test_Division $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:DivisionTests>)
target_link_libraries(test_Division PRIVATE DivisionTests)

add_library(NumericExpressions INTERFACE)
target_link_libraries(NumericExpressions INTERFACE Constant Variable Addition
        Subtraction Multiplication Division)
