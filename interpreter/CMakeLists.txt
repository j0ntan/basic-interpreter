add_library(NumericExpressions STATIC
        Constant.cpp
        Variable.cpp
        Array.cpp
        Addition.cpp
        Subtraction.cpp
        Multiplication.cpp
        Division.cpp
        )

add_library(BooleanExpressions STATIC LessThan.cpp Equals.cpp)

add_library(Commands STATIC
        Print.cpp
        AssignVariable.cpp
        AssignArray.cpp
        Goto.cpp
        IfThen.cpp
        GoSub.cpp
        Return.cpp
        End.cpp
        )
