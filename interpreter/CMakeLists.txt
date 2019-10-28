include_directories(NumericExpressions BooleanExpressions Commands)

add_library(Constant STATIC NumericExpressions/Constant.cpp)
add_library(Variable STATIC NumericExpressions/Variable.cpp)
target_link_libraries(Variable PRIVATE Constant)
add_library(Addition STATIC NumericExpressions/Addition.cpp)
add_library(Subtraction STATIC NumericExpressions/Subtraction.cpp)
add_library(Multiplication STATIC NumericExpressions/Multiplication.cpp)
add_library(Division STATIC NumericExpressions/Division.cpp)

add_library(LessThan STATIC BooleanExpressions/LessThan.cpp)
add_library(Equals STATIC BooleanExpressions/Equals.cpp)

add_library(Print STATIC Commands/Print.cpp)
add_library(AssignVariable STATIC Commands/AssignVariable.cpp)
add_library(AssignArray STATIC Commands/AssignArray.cpp)
add_library(Goto STATIC Commands/Goto.cpp)
add_library(IfThen STATIC Commands/IfThen.cpp)
add_library(GoSub STATIC Commands/GoSub.cpp)
add_library(Return STATIC Commands/Return.cpp)
add_library(End STATIC Commands/End.cpp)

add_library(ParserHelper STATIC Parser/ParserHelper.cpp)

add_library(Parser STATIC Parser/Parser.cpp)
target_link_libraries(Parser PRIVATE
        Constant
        Variable
        Addition
        Subtraction
        Multiplication
        Division
        Print
        AssignVariable
        AssignArray
        Goto
        LessThan
        Equals
        IfThen
        GoSub
        )
