add_library(LessThan STATIC LessThan.cpp)
add_library(Equals STATIC Equals.cpp)
add_library(BooleanExpressions $<TARGET_OBJECTS:LessThan>
        $<TARGET_OBJECTS:Equals>)
