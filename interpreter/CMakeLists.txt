add_library(NumericExpressions STATIC
        NumericExpressions/Constant.cpp
        NumericExpressions/Variable.cpp
        NumericExpressions/Array.cpp
        NumericExpressions/Addition.cpp
        NumericExpressions/Subtraction.cpp
        NumericExpressions/Multiplication.cpp
        NumericExpressions/Division.cpp
        )

add_library(BooleanExpressions STATIC
        BooleanExpressions/LessThan.cpp
        BooleanExpressions/Equals.cpp
        )
target_include_directories(BooleanExpressions PRIVATE NumericExpressions)

add_library(Commands STATIC
        Commands/Print.cpp
        Commands/AssignVariable.cpp
        Commands/AssignArray.cpp
        Commands/Goto.cpp
        Commands/IfThen.cpp
        Commands/GoSub.cpp
        Commands/Return.cpp
        Commands/End.cpp
        )
target_include_directories(Commands PRIVATE NumericExpressions BooleanExpressions)
