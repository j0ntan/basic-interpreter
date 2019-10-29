add_library(NumericExpression INTERFACE)
target_include_directories(NumericExpression INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Constant Constant.cpp)
target_link_libraries(Constant PUBLIC NumericExpression)

add_library(Variable Variable.cpp)
target_link_libraries(Variable PUBLIC NumericExpression)

add_library(BinaryExpression INTERFACE)
target_link_libraries(BinaryExpression INTERFACE NumericExpression)

add_library(Addition Addition.cpp)
target_link_libraries(Addition PUBLIC BinaryExpression)

add_library(Subtraction Subtraction.cpp)
target_link_libraries(Subtraction PUBLIC BinaryExpression)

add_library(Multiplication Multiplication.cpp)
target_link_libraries(Multiplication PUBLIC BinaryExpression)

add_library(Division Division.cpp)
target_link_libraries(Division PUBLIC BinaryExpression)

add_library(NumericExpressions INTERFACE)
target_link_libraries(NumericExpressions INTERFACE Constant Variable Addition
        Subtraction Multiplication Division)
