add_library(Print STATIC Print.cpp)
add_library(AssignVariable STATIC AssignVariable.cpp)
add_library(AssignArray STATIC AssignArray.cpp)
add_library(Goto STATIC Goto.cpp)
add_library(IfThen STATIC IfThen.cpp)
add_library(GoSub STATIC GoSub.cpp)
add_library(Return STATIC Return.cpp)
add_library(End STATIC End.cpp)
add_library(Commands $<TARGET_OBJECTS:Print> $<TARGET_OBJECTS:AssignVariable>
        $<TARGET_OBJECTS:AssignArray> $<TARGET_OBJECTS:Goto>
        $<TARGET_OBJECTS:IfThen> $<TARGET_OBJECTS:GoSub>
        $<TARGET_OBJECTS:Return> $<TARGET_OBJECTS:End>)
