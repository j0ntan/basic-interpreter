add_executable(test_Constant Constant.cpp)
target_include_directories(test_Constant PRIVATE ${INTERPRETER_INCLUDE})
target_link_libraries(test_Constant PRIVATE Constant gtest_main)
