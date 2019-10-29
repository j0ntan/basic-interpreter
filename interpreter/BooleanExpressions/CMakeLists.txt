add_library(BooleanExpression INTERFACE)
target_include_directories(BooleanExpression INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BooleanExpression INTERFACE NumericExpression)

add_library(LessThan LessThan.cpp)
target_link_libraries(LessThan PUBLIC BooleanExpression)

add_library(Equals Equals.cpp)
target_link_libraries(Equals PUBLIC BooleanExpression)

add_library(BooleanExpressions INTERFACE)
target_link_libraries(BooleanExpressions INTERFACE LessThan Equals)
