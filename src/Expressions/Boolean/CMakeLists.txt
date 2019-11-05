add_library(LessThan LessThan.cpp)
add_library(LessThanTests LessThan.cpp)
target_link_libraries(LessThanTests PRIVATE LessThan Addition Variable Constant gtest)
add_executable(test_LessThan $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:LessThanTests>)
target_link_libraries(test_LessThan PRIVATE LessThanTests)

add_library(Equals Equals.cpp)
add_library(EqualsTests Equals.cpp)
target_link_libraries(EqualsTests PRIVATE Equals Addition Variable Constant gtest)
add_executable(test_Equals $<TARGET_OBJECTS:gtest_main> $<TARGET_OBJECTS:EqualsTests>)
target_link_libraries(test_Equals PRIVATE EqualsTests)

add_library(BooleanExpressions INTERFACE)
target_link_libraries(BooleanExpressions INTERFACE LessThan Equals)
