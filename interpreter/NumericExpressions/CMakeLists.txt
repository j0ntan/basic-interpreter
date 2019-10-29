add_library(Constant STATIC Constant.cpp)
add_library(Variable STATIC Variable.cpp)
add_library(Addition STATIC Addition.cpp)
add_library(Subtraction STATIC Subtraction.cpp)
add_library(Multiplication STATIC Multiplication.cpp)
add_library(Division STATIC Division.cpp)
add_library(NumericExpressions $<TARGET_OBJECTS:Constant>
        $<TARGET_OBJECTS:Variable> $<TARGET_OBJECTS:Addition>
        $<TARGET_OBJECTS:Subtraction> $<TARGET_OBJECTS:Multiplication>
        $<TARGET_OBJECTS:Division>)
