add_library(Constant STATIC Constant.cpp)

add_library(Variable STATIC Variable.cpp)
target_link_libraries(Variable PRIVATE Constant)

add_library(Array STATIC Array.cpp)

add_library(Addition STATIC Addition.cpp)

add_library(Subtraction STATIC Subtraction.cpp)

add_library(Multiplication STATIC Multiplication.cpp)

add_library(Division STATIC Division.cpp)

add_library(LessThan STATIC LessThan.cpp)

add_library(Equals STATIC Equals.cpp)

add_library(Print STATIC Print.cpp)

add_library(AssignVariable STATIC AssignVariable.cpp)

add_library(AssignArray STATIC AssignArray.cpp)

add_library(Goto STATIC Goto.cpp)

add_library(IfThen STATIC IfThen.cpp)

add_library(GoSub STATIC GoSub)

add_library(Return STATIC Return.cpp)

add_library(End STATIC End.cpp)
