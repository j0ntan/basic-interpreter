add_executable(test_Constant Constant.cpp)
target_include_directories(test_Constant PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Constant PRIVATE NumericExpressions gtest_main)

add_executable(test_Variable Variable.cpp)
target_include_directories(test_Variable PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Variable PRIVATE NumericExpressions gtest_main)

add_executable(test_Array Array.cpp)
target_include_directories(test_Array PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Array PRIVATE NumericExpressions gtest_main)

add_executable(test_Addition Addition.cpp)
target_include_directories(test_Addition PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Addition PRIVATE NumericExpressions gtest_main)

add_executable(test_Subtraction Subtraction.cpp)
target_include_directories(test_Subtraction PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Subtraction PRIVATE NumericExpressions gtest_main)

add_executable(test_Multiplication Multiplication.cpp)
target_include_directories(test_Multiplication PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Multiplication PRIVATE NumericExpressions gtest_main)

add_executable(test_Division Division.cpp)
target_include_directories(test_Division PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Division PRIVATE NumericExpressions gtest_main)

add_executable(test_LessThan LessThan.cpp)
target_include_directories(test_LessThan PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_LessThan PRIVATE BooleanExpressions NumericExpressions gtest_main)

add_executable(test_Equals Equals.cpp)
target_include_directories(test_Equals PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Equals PRIVATE BooleanExpressions NumericExpressions gtest_main)

add_executable(test_Print Print.cpp)
target_include_directories(test_Print PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Print PRIVATE Commands NumericExpressions gtest_main)

add_executable(test_AssignVariable AssignVariable.cpp)
target_include_directories(test_AssignVariable PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_AssignVariable PRIVATE Commands NumericExpressions gtest_main)

add_executable(test_AssignArray AssignArray.cpp)
target_include_directories(test_AssignArray PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_AssignArray PRIVATE Commands NumericExpressions gtest_main)

add_executable(test_Goto Goto.cpp)
target_include_directories(test_Goto PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Goto PRIVATE Commands gtest_main)

add_executable(test_IfThen IfThen.cpp)
target_include_directories(test_IfThen PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_IfThen PRIVATE
        Commands
        BooleanExpressions
        NumericExpressions
        gtest_main
        )

add_executable(test_GoSub GoSub.cpp)
target_include_directories(test_GoSub PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_GoSub PRIVATE Commands gtest_main)

add_executable(test_Return Return.cpp)
target_include_directories(test_Return PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Return PRIVATE Commands gtest_main)

add_executable(test_End End.cpp)
target_include_directories(test_End PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_End PRIVATE Commands gtest_main)
