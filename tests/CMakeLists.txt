add_executable(test_Constant Constant.cpp)
target_include_directories(test_Constant PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Constant PRIVATE Constant gtest_main)

add_executable(test_Variable Variable.cpp)
target_include_directories(test_Variable PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Variable PRIVATE Variable gtest_main)
