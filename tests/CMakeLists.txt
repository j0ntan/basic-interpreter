add_executable(test_Constant Constant.cpp)
target_include_directories(test_Constant PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Constant PRIVATE Constant gtest_main)

add_executable(test_Variable Variable.cpp)
target_include_directories(test_Variable PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Variable PRIVATE Variable gtest_main)

add_executable(test_Array Array.cpp)
target_include_directories(test_Array PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Array PRIVATE Array gtest_main)

add_executable(test_Addition Addition.cpp)
target_include_directories(test_Addition PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Addition PRIVATE
        Addition
        Variable
        Constant
        gtest_main
        )

add_executable(test_Subtraction Subtraction.cpp)
target_include_directories(test_Subtraction PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Subtraction PRIVATE
        Subtraction
        Variable
        Constant
        gtest_main
        )

add_executable(test_Multiplication Multiplication.cpp)
target_include_directories(test_Multiplication PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Multiplication PRIVATE
        Multiplication
        Variable
        Constant
        gtest_main
        )

add_executable(test_Division Division.cpp)
target_include_directories(test_Division PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Division PRIVATE
        Division
        Variable
        Constant
        gtest_main
        )

add_executable(test_LessThan LessThan.cpp)
target_include_directories(test_LessThan PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_LessThan PRIVATE
        LessThan
        Addition
        Variable
        Constant
        gtest_main
        )

add_executable(test_Equals Equals.cpp)
target_include_directories(test_Equals PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Equals PRIVATE
        Equals
        Addition
        Variable
        Constant
        gtest_main
        )
